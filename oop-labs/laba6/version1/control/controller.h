#ifndef LABA1_CONTROLLER_H
#define LABA1_CONTROLLER_H
#include "../field/field.h"
#include "../field/fieldView.h"
#include "strategy/levelContext.h"
#include "strategy/levels/firstLevel.h"
#include "strategy/levels/secondLevel.h"

class Controller {

private:
    fieldView viewField;
    levelContext context;

public:
    Controller();
    void setStep(Player::Step step);
    void showField();
    bool checkWin();
    bool checkLoss();
    void setLevel(char);
};


#endif//LABA1_CONTROLLER_H
