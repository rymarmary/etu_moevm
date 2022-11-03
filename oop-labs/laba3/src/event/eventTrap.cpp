#include "eventTrap.h"


void eventTrap::execute() {
    player->setHealth(player->getHealth()-1);
    Message message = Message(Levels::GAME, "Player was on trap cell, health decreased to " + std::to_string(player->getHealth()));
    LogPool::getInstance()->print(&message);

}


eventTrap::eventTrap(Player *player) {
    this->player = player;
}
