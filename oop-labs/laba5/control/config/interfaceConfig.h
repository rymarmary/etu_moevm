#ifndef LABA1_INTERFACECONFIG_H
#define LABA1_INTERFACECONFIG_H
#include <map>
#include "../../player/Player.h"

class interfaceConfig{
protected:
    std::map<char, Player::Step> config;
    const std::map<char, Player::Step> defaultConfig = {
            {'u', Player::Step::UP},
            {'d', Player::Step::DOWN},
            {'r', Player::Step::RIGHT},
            {'l', Player::Step::LEFT},
            {'e', Player::Step::EXIT}
    };
public:
    virtual std::map<char, Player::Step> getConfig() = 0;
    virtual ~interfaceConfig() = default;
    void isCorrect();
    std::map<char, Player::Step> getDefault();
};

#endif//LABA1_INTERFACECONFIG_H
