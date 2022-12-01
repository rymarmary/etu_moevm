#include "levelContext.h"

levelContext::levelContext(levelStrategy* strategy) : level(strategy) {}


void levelContext::setStrategy(levelStrategy* strategy) {
    delete level;
    level = strategy;
}


void levelContext::setLevel() {
    field = level->generateLevel();
}


Field *levelContext::getField() {
    return field;
}

levelContext::~levelContext() {
    delete level;
}
