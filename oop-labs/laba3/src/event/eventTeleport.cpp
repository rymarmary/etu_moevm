#include "eventTeleport.h"

eventTeleport::eventTeleport(Field *field) {
    this->field = field;
}


void eventTeleport::execute() {
    field->teleportPlayer();
    Message message = Message(Levels::GAME, "Player have been teleported.");
    LogPool::getInstance()->print(&message);
}
