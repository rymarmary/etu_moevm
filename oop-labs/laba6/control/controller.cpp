#include "controller.h"

Controller::Controller() : viewField(nullptr) {}


void Controller::setStep(Player::Step step) {
    try {
        context.getField()->playerMove(step);
    } catch (InvalidDataException& IDE) {
        Message message = Message(Levels::ERROR, IDE.what());
        LogPool::getInstance()->print(&message);
    } catch (OpenFileException& OPE) {
        Message message = Message(Levels::ERROR, OPE.what());
        LogPool::getInstance()->print(&message);
    } catch (RestoreStateException& RSE) {
        Message message = Message(Levels::ERROR, RSE.what());
        LogPool::getInstance()->print(&message);
    } catch (SaveStateException& SST) {
        Message message = Message(Levels::ERROR, SST.what());
        LogPool::getInstance()->print(&message);
    } catch (...) {
        Message message = Message(Levels::ERROR, "Failed processing command");
        LogPool::getInstance()->print(&message);
    }
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
