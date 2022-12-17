#ifndef LABA1_EVENTTRAP_H
#define LABA1_EVENTTRAP_H
#include "eventPlayer.h"
#include "../player/Player.h"

class eventTrap:public eventPlayer {
private:
    size_t hash;
public:
    void execute() override;
    explicit eventTrap(Player* player);
    size_t getHash() final;
};


#endif//LABA1_EVENTTRAP_H
