#ifndef LABA1_EVENTFIELD_H
#define LABA1_EVENTFIELD_H

class Field;
#include "event.h"

class eventField:public Event{
public:
    virtual void execute() override = 0;
protected:
    Field* field;
};


#endif//LABA1_EVENTFIELD_H
