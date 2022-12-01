#include "eventWalls.h"


eventWalls::eventWalls(Field *field) {
    this->field = field;
}


void eventWalls::execute() {
    field->setWalls();
    Message message = Message(Levels::GAME, "Walls have been settled");
    LogPool::getInstance()->print(&message);
}
