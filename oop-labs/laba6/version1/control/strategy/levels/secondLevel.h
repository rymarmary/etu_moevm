#ifndef LABA1_SECONDLEVEL_H
#define LABA1_SECONDLEVEL_H
#include "../levelStrategy.h"
#include "../../../field/fieldGenerator.h"


class secondLevel : public levelStrategy{
private:
    fieldGenerator<
            fieldSize<20, 20>,
            playerPosition<5, 5>,
            setWallsColumn<5, 6>,
            setWallsRow<2, 13>,
            spawnEventField<eventTeleport, false, 9, 17>,
            spawnEventPlayer<eventKey, 6, 9>,
            spawnEventPlayer<eventTrap, 4, 7>
            > generator;
public:
    Field* generateLevel() final;
};


#endif//LABA1_SECONDLEVEL_H
