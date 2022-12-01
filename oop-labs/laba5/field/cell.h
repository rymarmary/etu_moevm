#ifndef LABA1_CELL_H
#define LABA1_CELL_H

class Field;
#include "../event/event.h"
#include "../event/eventPlayer.h"
#include "../event/eventField.h"
#include "../event/eventTeleport.h"
#include "../event/eventKey.h"
#include "../event/eventWalls.h"
#include "../event/eventTrap.h"

class Cell{
private:
    bool possibility;
    bool playerOnCell;
    Event* event;
public:
    void setPossibility(bool possibility);
    bool getPossibility() const;
    void setPlayerOnCell(bool playerOnCell);
    bool getPlayerOnCell() const;
    void setEvent(Event* event);
    Event* getEvent() const;
    void update();
    explicit Cell(bool possibility = true, bool playerOnCell = false);
};

#endif//LABA1_CELL_H
