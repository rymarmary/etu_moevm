#ifndef LABA1_SPAWNEVENTPLAYER_H
#define LABA1_SPAWNEVENTPLAYER_H
#include "../../field/field.h"

template<class evPlayer, int row, int limit>
class spawnEventPlayer{
public:
    void operator()(Field* field){
        int tmp = row;
        auto* player = field->retPlayer();
        tmp %= field->getHeight();
        if (tmp < 0) tmp *= -1;
        int tmpLimit = limit;
        tmpLimit %= field->getWidth();
        if (tmpLimit < 0) tmpLimit *= -1;

        for (int i = 1; i < tmpLimit; i++){
            if (field->getCells()[tmp][i].getPossibility() && !field->getCells()[tmp][i].getPlayerOnCell()
                && field->getCells()[tmp][i].getEvent() == nullptr)
                field->getCells()[tmp][i].setEvent(new evPlayer(player));
        }
    }
};

#endif//LABA1_SPAWNEVENTPLAYER_H
