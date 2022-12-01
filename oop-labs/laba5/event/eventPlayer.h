#ifndef LABA1_EVENTPLAYER_H
#define LABA1_EVENTPLAYER_H

class Player;
#include "event.h"

class eventPlayer: public Event{
public:
    virtual void execute() override = 0;
protected:
    Player* player;
};


#endif//LABA1_EVENTPLAYER_H
