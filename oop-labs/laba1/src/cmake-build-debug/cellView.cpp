#include "cellView.h"

cellView::cellView(Cell cell) {
    if (cell.getPlayerOnCell()) option = ' p';
    else if(!cell.getPossibility()) option = 'x';
    else option = ' ';
}

char cellView::getOption() const {
    return option;
}
