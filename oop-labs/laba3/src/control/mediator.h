#ifndef LABA1_MEDIATOR_H
#define LABA1_MEDIATOR_H
#include "commandReader.h"
#include "controller.h"
#include "../log/LogPool.h"

class Mediator {

private:
    commandReader input;
    Controller game;

public:
    void start();
};


#endif//LABA1_MEDIATOR_H
