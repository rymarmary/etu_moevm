#ifndef LABA1_SETWALLSROW_H
#define LABA1_SETWALLSROW_H
#include "../../field/field.h"

template<int row, int limit>
class setWallsRow{
public:
    void operator()(Field* field){
        int tmp = row;
        tmp %= field->getHeight();
        if (tmp < 0) tmp *= -1;
        int tmpLimit = limit;
        tmpLimit %= field->getWidth();
        if (tmpLimit < 0) tmpLimit *= -1;

        for (int i = 1; i < tmpLimit; i++){
            if (field->getCells()[tmp][i].getPossibility() && !field->getCells()[tmp][i].getPlayerOnCell()
                && field->getCells()[tmp][i].getEvent() == nullptr)
                field->getCells()[tmp][i].setPossibility(false);
        }
    }
};

#endif//LABA1_SETWALLSROW_H
