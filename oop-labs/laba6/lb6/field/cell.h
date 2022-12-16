#ifndef LABA1_CELL_H
#define LABA1_CELL_H

class Field;
#include "../event/event.h"

class Cell{
private:
    bool possibility;
    bool playerOnCell = false;
    Event* event = nullptr;
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
