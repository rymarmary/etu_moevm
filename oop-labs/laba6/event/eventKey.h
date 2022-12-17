#ifndef LABA1_EVENTKEY_H
#define LABA1_EVENTKEY_H
#include "eventPlayer.h"
#include "../player/Player.h"

class eventKey: public eventPlayer{
private:
    size_t hash;
public:
    void execute() override;
    explicit eventKey(Player* player);
    size_t getHash() final;
};


#endif//LABA1_EVENTKEY_H
