#include "eventTeleport.h"
#include "../field/field.h"

eventTeleport::eventTeleport(Field *field) {
    this->field = field;
    hash = typeid(eventTeleport).hash_code();
}


void eventTeleport::execute() {
    field->teleportPlayer();
    Message message = Message(Levels::GAME, "Player have been teleported.");
    LogPool::getInstance()->print(&message);
}


size_t eventTeleport::getHash() {
    return hash;
}
