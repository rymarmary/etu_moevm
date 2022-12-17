#ifndef LABA1_FIRSTLEVEL_H
#define LABA1_FIRSTLEVEL_H
#include "../levelStrategy.h"
#include "../../../field/fieldGenerator.h"


class firstLevel final: public levelStrategy{
private:
    fieldGenerator<
            fieldSize<>,
            playerPosition<>,
            setWallsColumn<2, 5>,
            setWallsRow<3, 8>,
            spawnEventField<eventTeleport, true, 4, 2>,
            spawnEventPlayer<eventKey, 6, 3>,
            spawnEventPlayer<eventTrap, 7, 7>
            > generator;
public:
    Field* generateLevel() final;
};


#endif//LABA1_FIRSTLEVEL_H
