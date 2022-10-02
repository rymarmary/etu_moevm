#ifndef LABA1_CELL_H
#define LABA1_CELL_H
#include "event.h"
#include "Player.h"

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
    void update(Player& player);
    explicit Cell(bool possibility = true, bool playerOnCell = false);
};

#endif//LABA1_CELL_H
