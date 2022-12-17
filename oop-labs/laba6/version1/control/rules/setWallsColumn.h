#ifndef LABA1_SETWALLSCOLUMN_H
#define LABA1_SETWALLSCOLUMN_H
#include "../../field/field.h"

template<int column, int limit>
class setWallsColumn{
public:
    void operator()(Field* field){
        int tmp = column;
        tmp %= field->getWidth();
        if (tmp < 0) tmp *= -1;
        int tmpLimit = limit;
        tmpLimit %= field->getHeight();
        if (tmpLimit < 0) tmpLimit *= -1;

        for (int i = 1; i < tmpLimit; i++){
            if (field->getCells()[i][tmp].getPossibility() && !field->getCells()[i][tmp].getPlayerOnCell()
                && field->getCells()[i][tmp].getEvent() == nullptr)
                field->getCells()[i][tmp].setPossibility(false);
        }
    }
};

#endif//LABA1_SETWALLSCOLUMN_H
