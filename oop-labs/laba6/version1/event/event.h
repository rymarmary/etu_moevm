#ifndef LABA1_EVENT_H
#define LABA1_EVENT_H

#include <cstdio>
#include <typeinfo>
class Event {

public:
    virtual void execute() = 0;
    virtual ~Event() = default;
    virtual size_t getHash() = 0;
};

#endif//LABA1_EVENT_H
