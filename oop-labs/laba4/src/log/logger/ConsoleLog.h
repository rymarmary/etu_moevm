#ifndef LABA1_CONSOLELOG_H
#define LABA1_CONSOLELOG_H
#include "logger.h"
#include <iostream>

class ConsoleLog:public Logger{
public:
    void logOutput(Message*) override;
    ~ConsoleLog() override = default;
};


#endif//LABA1_CONSOLELOG_H
