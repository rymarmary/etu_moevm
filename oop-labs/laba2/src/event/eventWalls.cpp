#include "eventWalls.h"


eventWalls::eventWalls(Field *field) {
    this->field = field;
}


void eventWalls::execute() {
    field->setWalls();
}
