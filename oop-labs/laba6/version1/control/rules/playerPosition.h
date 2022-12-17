#ifndef LABA1_PLAYERPOSITION_H
#define LABA1_PLAYERPOSITION_H
#include "../../field/field.h"

template<int x=0, int y=0>
class playerPosition{
public:
    void operator()(Field* field) {
        if (x < field->getWidth() && y < field->getHeight()) {
            if (field->getCells()[y][x].getPossibility() && field->getCells()[y][x].getEvent() == nullptr) {
                field->playerPos(x, y);
                return;
            }
        }
        field->playerPos(0, 0);
    }
};

#endif//LABA1_PLAYERPOSITION_H
