#ifndef LABA1_CONTROLLER_H
#define LABA1_CONTROLLER_H
#include "../field/field.h"
#include "../field/fieldView.h"

class Controller {

private:
    Field field;
    fieldView viewField;
    Player player;

public:
    Controller();
    void setField(int width, int height);
    void setDefaultField();
    void setStep(Player::Step step);
    void showField();
    bool checkWin();
    bool checkLoss();
};


#endif//LABA1_CONTROLLER_H
