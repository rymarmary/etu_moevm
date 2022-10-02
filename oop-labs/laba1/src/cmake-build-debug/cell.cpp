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
    if (this->event != nullptr) this->event->~Event();
    this->event = event;
}

void Cell::update(Player& player) {
    event->execute(player);
}

Event* Cell::getEvent() const {
    return event;
}

Cell::Cell(bool possibility, bool playerOnCell) : possibility(possibility), playerOnCell(playerOnCell){}
