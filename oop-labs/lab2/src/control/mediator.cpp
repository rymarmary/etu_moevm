#include "mediator.h"

void Mediator::start() {
    input.readChar();

    if (input.getChar() != 'y') {
        input.readSize();
        game.setField(input.getWidth(), input.getHeight());
    } else {
        game.setDefaultField();
    }

    while(input.getStep() != Player::EXIT) {
        game.showField();
        input.readStep();
        game.setStep(input.getStep());
        if (game.checkLoss()) {
            input.printDeath();
            return;
        }
        if (game.checkWin()) {
            input.printWin();
            return;
        }
    }
}
