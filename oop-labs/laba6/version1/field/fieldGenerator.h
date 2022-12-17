#ifndef LABA1_FIELDGENERATOR_H
#define LABA1_FIELDGENERATOR_H
#include "field.h"
#include "../control/rules/fieldSize.h"
#include "../control/rules/playerPosition.h"
#include "../control/rules/setWallsColumn.h"
#include "../control/rules/setWallsRow.h"
#include "../control/rules/spawnEventField.h"
#include "../control/rules/spawnEventPlayer.h"

template<class... Rules>
class fieldGenerator{
public:
    Field* createField(){
        auto* field = new Field;
        (Rules()(field),...);
        return field;
    }
};

#endif//LABA1_FIELDGENERATOR_H
