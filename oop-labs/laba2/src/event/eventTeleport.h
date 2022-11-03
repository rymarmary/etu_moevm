#ifndef LABA1_EVENTTELEPORT_H
#define LABA1_EVENTTELEPORT_H
#include "../event/eventField.h"
#include "../field/field.h"

class eventTeleport: public eventField{
public:
    explicit eventTeleport(Field* field);
    void execute() override;
};


#endif//LABA1_EVENTTELEPORT_H
