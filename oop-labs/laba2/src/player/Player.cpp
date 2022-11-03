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

Player::Player(int health, int keys, int protection) : health(health), keys(keys), protection(protection) {}