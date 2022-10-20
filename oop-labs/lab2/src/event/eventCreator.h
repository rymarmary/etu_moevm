#ifndef LABA1_EVENTCREATOR_H
#define LABA1_EVENTCREATOR_H

#include "../field/field.h"
#include "eventKey.h"
#include "eventTrap.h"
#include "eventWalls.h"
#include "eventTeleport.h"


class eventCreator {
private:
    Field* field;
    Player* player;
public:
    explicit eventCreator(Field* field, Player* player);
    void setEvents();
};


#endif//LABA1_EVENTCREATOR_H
