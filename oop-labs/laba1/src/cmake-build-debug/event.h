#ifndef LABA1_EVENT_H
#define LABA1_EVENT_H
#include "Player.h"

class Event {

public:
    virtual void execute(Player& player) = 0;
    virtual ~Event() = default;
};

#endif//LABA1_EVENT_H
