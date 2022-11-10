#include "field.h"


Field::Field(int width, int height) : width(width), height(height), playerCoordinates({0,0}) {
    for(int i = 0; i != height; ++i) {
        cells.emplace_back();
        for(int j = 0; j != width; ++j) {
            cells.at(i).emplace_back();
        }
    }
}


void Field::makeField(Player& player) {
    cells.at(0).at(0).setPlayerOnCell(true);
    eventCreator creator(this, &player);
    creator.setEvents();
    for (int i=0; i != height; ++i){
        for (int j=0; j != width; ++j){
            if (i==j+1) cells.at(i).at(j).setPossibility(false);
        }
    }
    Message message = Message(Levels::GAME, "Field have been created.");
    LogPool::getInstance()->print(&message);
}


int Field::getWidth() const {
    return width;
}


int Field::getHeight() const {
    return height;
}


std::vector<std::vector<Cell>> &Field::getCells() {
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
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setEvent(nullptr);
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
    if (cells.at(tempCoord.second).at(tempCoord.first).getPossibility()) {
        playerCoordinates = tempCoord;
        Message message = Message(Levels::GAME, "Player moved to " + std::to_string(playerCoordinates.first) + " " + std::to_string(playerCoordinates.second));
        LogPool::getInstance()->print(&message);
    }
    cells.at(playerCoordinates.second).at(playerCoordinates.first).update();
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(true);
}


void Field::setWalls() {
    for (int i=0; i != height; ++i){
        for (int j=0; j != width; ++j){
            if (j == i - 2) cells.at(i).at(j).setPossibility(false);
        }
    }
}


void Field::teleportPlayer() {
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> generateX(0, width-1);
    std::uniform_int_distribution<int> generateY(0, height-1);
    std::pair<int,int> newCoords = {generateX(rng), generateY(rng)};
    while (!cells.at(newCoords.first).at(newCoords.second).getPossibility()
           || cells.at(newCoords.first).at(newCoords.second).getEvent() != nullptr){
        newCoords = {generateX(rng), generateY(rng)};
    }
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(false);
    playerCoordinates = newCoords;
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(true);
}
