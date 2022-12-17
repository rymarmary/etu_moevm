#ifndef LABA1_EVENTTELEPORT_H
#define LABA1_EVENTTELEPORT_H
#include "../event/eventField.h"


class eventTeleport: public eventField{
private:
    size_t hash;
public:
    explicit eventTeleport(Field* field);
    void execute() override;
    size_t getHash() final;
};


#endif//LABA1_EVENTTELEPORT_H
