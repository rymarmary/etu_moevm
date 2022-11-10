#ifndef LABA1_LOGGER_H
#define LABA1_LOGGER_H
#include "../Message.h"

class Logger{
public:
    virtual void logOutput(Message*) = 0;
    virtual ~Logger() = default;
};

#endif//LABA1_LOGGER_H
