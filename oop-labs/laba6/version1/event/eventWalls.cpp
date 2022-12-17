#include "eventWalls.h"
#include "../field/field.h"

eventWalls::eventWalls(Field *field) {
    this->field = field;
    hash = typeid(eventWalls).hash_code();
}


void eventWalls::execute() {
    field->setWalls();
    Message message = Message(Levels::GAME, "Walls have been settled");
    LogPool::getInstance()->print(&message);
}


size_t eventWalls::getHash() {
    return hash;
}
