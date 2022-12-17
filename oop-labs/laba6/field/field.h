#ifndef LABA1_FIELD_H
#define LABA1_FIELD_H
class Cell;
#include "cell.h"
#include "../player/Player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "../log/Message.h"
#include "../log/LogPool.h"
#include "../control/save/Memento.h"
#include "../control/save/Originator.h"

#include "../event/eventKey.h"
#include "../event/eventTrap.h"
#include "../event/eventTeleport.h"
#include "../event/eventWalls.h"
#include <functional>

#include "../control/exceptions/OpenFileException.h"
#include "../control/exceptions/RestoreStateException.h"
#include "../control/exceptions/SaveStateException.h"
#include "../control/exceptions/InvalidDataException.h"

#define FILESAVEFIELD "saveField.txt"
#define FILESAVEPLAYER "savePlayer.txt"

class Field:public Originator {

private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    std::pair<int,int> playerCoordinates;
    void swap(Field& other);
    Player* player;
    void saveGame();
    eventTrap tmp = eventTrap(player);
    std::map<size_t, std::string> eventToString = {
            {typeid(eventTrap).hash_code(), "eventTrap"},
            {typeid(eventTeleport).hash_code(), "eventTeleport"},
            {typeid(eventWalls).hash_code(), "eventWalls"},
            {typeid(eventKey).hash_code(), "eventKey"}
    };
    std::map<std::string, std::function<Event*()>> stringToEvent = {
            {"eventTrap", [this](){return new eventTrap(player);}},
            {"eventTeleport", [this](){return new eventTeleport(this);}},
            {"eventKey", [this](){return new eventKey(player);}},
            {"eventWalls", [this](){return new eventWalls(this);}}
    };
    std::tuple<int, int, std::pair<int, int>, std::vector<std::vector<Cell>>> restoredData;

public:
    Field(int width = 10, int height = 10);
    int getWidth() const;
    int getHeight() const;
    std::vector<std::vector<Cell>> &getCells();
    Field(const Field& other); // конструктор копирования
    Field& operator = (const Field& other); // оператор присваивания classic
    Field(Field&& other);  // конструктор перемещения
    Field& operator = (Field&& other); // оператор присваивания перемещения
    void playerMove(Player::Step move);
    void setWalls();
    void teleportPlayer();
    void playerPos(int x, int y);
    Player* retPlayer();
    std::string getState();
    void setState(std::string);
    size_t hash(int, int, std::pair<int, int>, std::vector<std::vector<Cell>>);
    void restoreState();
    void restoreGame();
//    ~Field();
};

#endif//LABA1_FIELD_H
