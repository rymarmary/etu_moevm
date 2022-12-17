#include "cell.h"

void Cell::setPossibility(bool possibility) {
    this->possibility = possibility;
}
bool Cell::getPossibility() const {
    return possibility;
}
void Cell::setPlayerOnCell(bool playerOnCell) {
    this->playerOnCell = playerOnCell;
}

bool Cell::getPlayerOnCell() const {
    return playerOnCell;
}

void Cell::setEvent(Event* event) {
    delete this->event;
    this->event = event;
}

void Cell::update() {
    if (event != nullptr)
        event->execute();
}

Event* Cell::getEvent() const {
    return event;
}

Cell::Cell(bool possibility, bool playerOnCell) : possibility(possibility), playerOnCell(playerOnCell), event(nullptr){}
