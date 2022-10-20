#include "eventTrap.h"


void eventTrap::execute() {
    player->setHealth(player->getHealth()-1);
}


eventTrap::eventTrap(Player *player) {
    this->player = player;
}
