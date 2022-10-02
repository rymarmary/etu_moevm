#include "controller.h"

Controller::Controller() : field(Field()), viewField(fieldView(field)){}

void Controller::setField(int width, int height) {
    field = Field(width, height);
    field.makeField();
}

void Controller::setDefaultField() {
    field = Field();
    field.makeField();
}

void Controller::setStep(Player::Step step) {
    field.playerMove(step);
}

void Controller::showField() {
    viewField = fieldView(field);
    viewField.printField();
}