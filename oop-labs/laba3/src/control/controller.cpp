#include "controller.h"

Controller::Controller() : field(Field()), viewField(fieldView(field)), player(Player()){}

void Controller::setField(int width, int height) {
    field = Field(width, height);
    field.makeField(player);
}


void Controller::setDefaultField() {
    field = Field();
    field.makeField(player);
}


void Controller::setStep(Player::Step step) {
    field.playerMove(step);
}


void Controller::showField() {
    viewField = fieldView(field);
    viewField.printField();
}


bool Controller::checkWin() {
    if (player.getKeys() == 1) return true;
    return false;
}


bool Controller::checkLoss() {
    if (player.getHealth() <= 0) return true;
    return false;
}
