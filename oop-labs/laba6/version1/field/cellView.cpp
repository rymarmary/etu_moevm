#include "cellView.h"

cellView::cellView(Cell cell) {
    if (cell.getPlayerOnCell()) option = 'p';
    else if(!cell.getPossibility()) option = 'x';
    else if (dynamic_cast<eventKey*>(cell.getEvent()) != nullptr) option = 'k';
    else if (dynamic_cast<eventWalls*>(cell.getEvent()) != nullptr) option = 'w';
    else if (dynamic_cast<eventTrap*>(cell.getEvent()) != nullptr) option = 't';
    else if (dynamic_cast<eventTeleport*>(cell.getEvent()) != nullptr) option = '*';
    else option = ' ';
}

char cellView::getOption() const {
    return option;
}
