#include "field.h"

Field::Field(int width, int height) : width(width), height(height), playerCoordinates({0,0}) {
    for(int i = 0; i != height; ++i) {
        cells.emplace_back();
        for(int j = 0; j != width; ++j) {
            cells.at(i).emplace_back();
        }
    }
}

void Field::makeField() {
    cells.at(0).at(0).setPlayerOnCell(true);
    for (int i=0; i != width; ++i){
        for (int j=0; j != height; ++j){
            if (i==j+1) cells.at(i).at(j).setPossibility(false);
        }
    }
}

int Field::getWidth() const {
    return width;
}

int Field::getHeight() const {
    return height;
}

std::vector<std::vector<Cell>> Field::getCells() const{
    return cells;
}

Field::Field(const Field &other) : width(other.width), height(other.height), playerCoordinates(other.playerCoordinates) {  // конструктор копирования definition
    cells = other.cells;
}

void Field::swap(Field &other) { // функция swap пока что только для конструктора перемещения
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(playerCoordinates, other.playerCoordinates);
    std::swap(cells, other.cells);
}

Field::Field(Field &&other) {  // конструктор перемещения
    this->swap(other); // применяем собственный метод
}

Field& Field::operator=(const Field &other) { // оператор присваивания classic
    if (this != &other) Field(other).swap(*this);
    return *this;
}

Field& Field::operator = (Field&& other) { // оператор присвания перемещения
    if (this != &other) this->swap(other);
    return *this;
}

void Field::playerMove(Player::Step move) {
    auto tempCoord = playerCoordinates;
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(false);
    switch (move){
        case Player::UP:
            tempCoord.second--;
            break;
        case Player::DOWN:
            tempCoord.second++;
            break;
        case Player::LEFT:
            tempCoord.first--;
            break;
        case Player::RIGHT:
            tempCoord.first++;
            break;
        default:
            break;
    }
    if (tempCoord.first < 0) tempCoord.first += width;
    if (tempCoord.second < 0) tempCoord.second += height;
    tempCoord.first %= width;
    tempCoord.second %= height;
    if (cells.at(tempCoord.second).at(tempCoord.first).getPossibility()) playerCoordinates = tempCoord;
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(true);
}
