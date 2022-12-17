#include "mediator.h"

void Mediator::start() {

    LogPool::getInstance()->setLoggers(input.readLoggers());
    LogPool::getInstance()->setLevels(input.readLevels());

    Message message = Message(Levels::STATUS, "Game started");
    LogPool::getInstance()->print(&message);

    game.setLevel(input.getLevel());

    input.getSrc();

    auto config = setConfig();

    while(input.getStep() != Player::EXIT) {
        game.showField();
        input.readStep(config);
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
}


Mediator::Mediator() {
    cfg = new fileConfig;
}


Mediator::~Mediator() {
    LogPool::getInstance()->deleteLoggers();
    LogPool::getInstance()->deleteInstance();
    delete cfg;
}

std::map<char, Player::Step> Mediator::setConfig() {
    std::map<char, Player::Step> settings;
    if (input.readConfig() == 'y') {
        settings = cfg->getDefault();
    } else {
        settings = cfg->getConfig();
    }
    return settings;
}
