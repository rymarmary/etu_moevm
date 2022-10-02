#ifndef LABA1_FIELD_H
#define LABA1_FIELD_H
#include "cell.h"
#include "player.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Field {

private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    std::pair<int,int> playerCoordinates;
    void swap(Field& other);

public:
    Field(int width = 10, int height = 10);
    void makeField();
    int getWidth() const;
    int getHeight() const;
    std::vector<std::vector<Cell>> getCells() const;
    Field(const Field& other); // конструктор копирования
    Field& operator = (const Field& other); // оператор присваивания classic
    Field(Field&& other);  // конструктор перемещения
    Field& operator = (Field&& other); // оператор присваивания перемещения
    void playerMove(Player::Step move);
};

#endif//LABA1_FIELD_H
