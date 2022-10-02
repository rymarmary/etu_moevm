#ifndef LABA1_CONTROLLER_H
#define LABA1_CONTROLLER_H
#include "field.h"
#include "fieldView.h"

class Controller {

private:
    Field field;
    fieldView viewField;

public:
    Controller();
    void setField(int width, int height);
    void setDefaultField();
    void setStep(Player::Step step);
    void showField();
};


#endif//LABA1_CONTROLLER_H
