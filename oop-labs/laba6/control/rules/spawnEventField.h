#ifndef LABA1_SPAWNEVENTFIELD_H
#define LABA1_SPAWNEVENTFIELD_H
#include "../../field/field.h"

template<class evField, bool withForce, int column, int limit>
class spawnEventField{
public:
    void operator()(Field* field){
        int tmp = column;
        tmp %= field->getWidth();
        if (tmp < 0) tmp *= -1;
        int tmpLimit = limit;
        tmpLimit %= field->getHeight();
        if (tmpLimit < 0) tmpLimit *= -1;

        for (int i = 1; i < tmpLimit; i++) {
            if (!withForce) {
                if (field->getCells()[i][tmp].getPossibility() && !field->getCells()[i][tmp].getPlayerOnCell() && field->getCells()[i][tmp].getEvent() == nullptr)
                    field->getCells()[i][tmp].setEvent(new evField(field));
            }
            else{
                if (!field->getCells()[i][tmp].getPlayerOnCell()) {
                    field->getCells()[i][tmp].setPossibility(true);
                    field->getCells()[i][tmp].setEvent(new evField(field));
                }
            }
        }
    }
};


#endif//LABA1_SPAWNEVENTFIELD_H
