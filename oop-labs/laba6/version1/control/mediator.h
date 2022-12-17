#ifndef LABA1_MEDIATOR_H
#define LABA1_MEDIATOR_H
#include "commandReader.h"
#include "controller.h"
#include "../log/LogPool.h"
#include "config/fileConfig.h"

class Mediator {

private:
    commandReader input;
    Controller game;
    interfaceConfig* cfg;

public:
    void start();
    Mediator();
    ~Mediator();
    std::map<char, Player::Step> setConfig();
};


#endif//LABA1_MEDIATOR_H
