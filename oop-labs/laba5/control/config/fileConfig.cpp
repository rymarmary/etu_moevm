#include "fileConfig.h"

fileConfig::fileConfig(const std::string &fileName) {
    file.open(fileName, std::ios_base::in);
}


fileConfig::~fileConfig() {
    file.close();
}


std::map<char, Player::Step> fileConfig::getConfig() {
    if (!file.is_open()) return defaultConfig;
    std::string fileString;
    while (std::getline(file, fileString)){
        std::string prefix;
        char command = '\0';
        std::istringstream stream(fileString);
        stream >> prefix >> command;
        if (command == '\0') return defaultConfig;
        if (prefix == "UP:") config[command] = Player::UP;
        if (prefix == "DOWN:") config[command] = Player::DOWN;
        if (prefix == "LEFT:") config[command] = Player::LEFT;
        if (prefix == "RIGHT:") config[command] = Player::RIGHT;
        if (prefix == "EXIT:") config[command] = Player::EXIT;
    }
    isCorrect();
    return config;
}
