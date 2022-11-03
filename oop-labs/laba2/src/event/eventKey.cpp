#include "eventKey.h"


void eventKey::execute() {
    player->setKeys(player->getKeys()+1);
}


eventKey::eventKey(Player *player) {
    this->player = player;
}
