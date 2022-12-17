#include "eventKey.h"


void eventKey::execute() {
    player->setKeys(player->getKeys()+1);
    Message message = Message(Levels::GAME, "Health increased to " + std::to_string(player->getKeys()));
    LogPool::getInstance()->print(&message);
}


eventKey::eventKey(Player *player) {
    this->player = player;
    hash = typeid(eventKey).hash_code();
}


size_t eventKey::getHash() {
    return hash;
}
