#include "controller.h"

Controller::Controller() : viewField(nullptr) {}


void Controller::setStep(Player::Step step) {
    context.getField()->playerMove(step);
}


void Controller::showField() {
    viewField = fieldView(context.getField());
    viewField.printField();
}


bool Controller::checkWin() {
    if (context.getField()->retPlayer()->getKeys() == 1) return true;
    return false;
}


bool Controller::checkLoss() {
    if (context.getField()->retPlayer()->getHealth() <= 0) return true;
    return false;
}


void Controller::setLevel(char lvl) {
    if(lvl == '1')
        context.setStrategy(new firstLevel);
    else
        context.setStrategy(new secondLevel);
    context.setLevel();
}
