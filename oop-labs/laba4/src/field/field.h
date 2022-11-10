#ifndef LABA1_FIELD_H
#define LABA1_FIELD_H
class Cell;
#include "../event/eventCreator.h"
#include "cell.h"
#include "../player/Player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "../log/Message.h"
#include "../log/LogPool.h"

class Field {

private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    std::pair<int,int> playerCoordinates;
    void swap(Field& other);

public:
    Field(int width = 10, int height = 10);
    void makeField(Player& player);
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
//    ~Field();
};

#endif//LABA1_FIELD_H
