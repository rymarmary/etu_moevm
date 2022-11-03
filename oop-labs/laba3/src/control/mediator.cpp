#include "mediator.h"

void Mediator::start() {
    LogPool::getInstance()->setLoggers(input.readLoggers());
    LogPool::getInstance()->setLevels(input.readLevels());

    Message message = Message(Levels::STATUS, "Game started");
    LogPool::getInstance()->print(&message);

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
    message = Message(Levels::STATUS, "Game finished");
    LogPool::getInstance()->print(&message);

    LogPool::getInstance()->deleteLoggers();
    LogPool::getInstance()->deleteInstance();
}
