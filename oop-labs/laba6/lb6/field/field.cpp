#include "field.h"


Field::Field(int width, int height) : width(width), height(height), playerCoordinates({0,0}), player(new Player) {
    for(int i = 0; i != height; ++i) {
        cells.emplace_back();
        for(int j = 0; j != width; ++j) {
            cells.at(i).emplace_back();
        }
    }
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
    std::swap(player, other.player);
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
        case Player::LOAD:
            saveGame();
            break;
        case Player::RESTORE:
            restoreGame();
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


void Field::playerPos(int x, int y) {
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(false);
    playerCoordinates = {x, y};
    cells.at(playerCoordinates.second).at(playerCoordinates.first).setPlayerOnCell(true);
}


Player *Field::retPlayer() {
    return player;
}


void Field::saveGame() {
    Memento memento;
    memento.saveState(getState(), FILESAVEFIELD);
    memento.saveState(player->getState(), FILESAVEPLAYER);
}


std::string Field::getState() {
    std::string fieldParams;
    fieldParams += std::to_string(hash(width, height, playerCoordinates, cells)) + '\n';
    fieldParams += std::to_string(width) + '\n';
    fieldParams += std::to_string(height) + '\n';
    fieldParams += std::to_string(playerCoordinates.first) + '\n';
    fieldParams += std::to_string(playerCoordinates.second) + '\n';
    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            if (cells.at(h).at(w).getEvent() != nullptr){
                if (eventToString.find(cells.at(h).at(w).getEvent()->getHash()) == eventToString.end()) fieldParams += "None\n";
                else fieldParams += eventToString.at(cells.at(h).at(w).getEvent()->getHash()) + '\n';
            } else fieldParams += "None\n";
        }
    }
    return fieldParams;
}


void Field::setState(std::string str) {
    std::vector<int> data;
    auto ss = std::stringstream {str};
    bool isReadHash = false;
    std::string hashFromFile;
    int count = 0;
    std::vector<std::vector<Cell>> cellsRestore;
    cellsRestore.emplace_back();
    int h = 0;
    int w = 0;
    try {
        for (std::string line; std::getline(ss, line, '\n'); ){
            if (!isReadHash) {
                hashFromFile = line;
                isReadHash = true;
                continue;
            }
            if (count < 4) data.push_back(std::stoi(line));
            else {
                cellsRestore.at(h).emplace_back();
                if (line != "None") {
                    cellsRestore.at(h).at(w).setEvent(stringToEvent.at(line)());
                }
            }
            ++w;
            int tmp_h = h;
            h += w / data[0];
            if (tmp_h != h) cellsRestore.emplace_back();
            w %= data[0];
        }
    } catch (...){
        throw std::invalid_argument("poo");
    }
    size_t fieldHash = hash(data[0], data[1], std::pair<int, int>(data[2], data[3]), cellsRestore);
    if (std::to_string(fieldHash) != hashFromFile) throw std::invalid_argument("fucking shit");
    else restoredData = std::make_tuple(data[0], data[1], std::make_pair(data[2], data[3]), cellsRestore);
}


size_t Field::hash(int width, int height, std::pair<int, int> playerCoordinates, std::vector<std::vector<Cell>> cells) {
    size_t hashWidth = std::hash<int>()(width);
    size_t hashHeight = std::hash<int>()(height);
    size_t hashCoordFirst = std::hash<int>()(playerCoordinates.first);
    size_t hashCoordSecond = std::hash<int>()(playerCoordinates.second);
    size_t hashCells = size_t(0);
    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            if (cells.at(h).at(w).getEvent() != nullptr) {
                hashCells += cells.at(h).at(w).getEvent()->getHash();
            }
        }
    }
    return (hashWidth << hashWidth) + (hashHeight << hashHeight) + (hashCoordFirst << hashCoordFirst) + (hashCoordSecond << hashCoordSecond) + (hashCells << hashCells);
}


void Field::restoreState() {
    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            delete cells.at(h).at(w).getEvent();
        }
    }
    cells.clear();
    width = std::get<0>(restoredData);
    height = std::get<1>(restoredData);
    playerCoordinates = std::get<2>(restoredData);
    cells = std::get<3>(restoredData);
}


void Field::restoreGame() {
    Memento memento;
    try{
        player->setState(memento.restoreState(FILESAVEPLAYER));
        setState(memento.restoreState(FILESAVEFIELD));
        player->restoreState();
        restoreState();
    } catch (...) {
        std::invalid_argument("poo");
    }
}
