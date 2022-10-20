#include "eventTeleport.h"

eventTeleport::eventTeleport(Field *field) {
    this->field = field;
}


void eventTeleport::execute() {
    field->teleportPlayer();
}
