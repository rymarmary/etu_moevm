#ifndef LABA1_EVENTKEY_H
#define LABA1_EVENTKEY_H
#include "eventPlayer.h"

class eventKey: public eventPlayer{
public:
    void execute() override;
    explicit eventKey(Player* player);
};


#endif//LABA1_EVENTKEY_H
