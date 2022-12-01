#ifndef LABA1_EVENTTRAP_H
#define LABA1_EVENTTRAP_H
#include "eventPlayer.h"

class eventTrap:public eventPlayer {
public:
    void execute() override;
    explicit eventTrap(Player* player);
};


#endif//LABA1_EVENTTRAP_H
