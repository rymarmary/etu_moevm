#ifndef LABA1_CELLVIEW_H
#define LABA1_CELLVIEW_H
#include "cell.h"
#include "../event/eventKey.h"
#include "../event/eventWalls.h"
#include "../event/eventTeleport.h"
#include "../event/eventTrap.h"

class cellView {

private:
    char option;

public:
    explicit cellView(Cell cell);
    char getOption() const;
};


#endif//LABA1_CELLVIEW_H
