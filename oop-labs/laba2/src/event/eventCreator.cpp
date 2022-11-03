#include "eventCreator.h"
#include <random>

eventCreator::eventCreator(Field *field, Player *player) {
    this->field = field;
    this->player = player;
}


void eventCreator::setEvents() {
    field->getCells().at(field->getHeight()-1).at(0).setEvent(new eventKey(player));
    field->getCells().at(field->getHeight()-1).at(field->getWidth()-1).setEvent(new eventTrap(player));
    field->getCells().at(0).at(field->getWidth()-1).setEvent(new eventTeleport(field));
    field->getCells().at(0).at(field->getWidth()/2).setEvent(new eventWalls(field));
}
