#include "Player.h"

void Player::setHealth(int health){
    this->health = health;
}

int Player::getHealth(){
    return health;
}

void Player::setKeys(int keys){
    this->keys = keys;
}

int Player::getKeys(){
    return keys;
}

void Player::setProtection(int protection){
    this->protection = protection;
}

int Player::getProtection(){
    return protection;
}

Player::Player(int health, int keys, int protection) : health(health), keys(keys), protection(protection) {
    Message message = Message(Levels::GAME, "U have created a player");
    LogPool::getInstance()->print(&message);
}


std::string Player::getState() {
    std::string saveData;
    saveData += std::to_string (hash(keys, health, protection));
    saveData += "\n" + std::to_string(keys) + "\n" + std::to_string(health) + "\n" + std::to_string(protection);
    return saveData;

}


size_t Player::hash(int keys, int health, int protection) {
    size_t hashKeys = std::max(size_t(100), std::hash<int>()(keys*100));
    size_t hashHealth = std::max(size_t(100), std::hash<int>()(health*100));
    size_t hashProtection = std::max(size_t(100), std::hash<int>()(protection*100));
    return (hashKeys<<hashKeys) xor (hashHealth<<hashHealth) xor (hashProtection<<hashProtection); // для шифрования данных
}


void Player::setState(std::string str) {
    std::vector<int> data;
    auto ss = std::stringstream {str};
    bool isReadHash = false;
    std::string hashFromFile;
    try {
        for (std::string line; std::getline(ss, line, '\n'); ){
            if (!isReadHash) {
                hashFromFile = line;
                isReadHash = true;
            }
            data.push_back(std::stoi(line));
        }
    } catch (...){
        throw std::invalid_argument("poo");
    }
    if (hashFromFile == std::to_string(hash(data[0], data[1], data[2]))){
        restoredData = data;
    } else if (data.size() != TOTALVAL) {
        throw std::invalid_argument("poo");
    }
    else {
        throw std::invalid_argument("poo");
    }
}


void Player::restoreState() {
    keys = restoredData[0];
    health = restoredData[1];
    protection = restoredData[2];
}
