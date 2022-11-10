#include "interfaceConfig.h"


void interfaceConfig::isCorrect() {
    if (config.size()<5) config=defaultConfig;
}


std::map<char, Player::Step> interfaceConfig::getDefault() {
    return defaultConfig;
}
