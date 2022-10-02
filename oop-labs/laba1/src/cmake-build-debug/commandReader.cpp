#include "commandReader.h"

void commandReader::readSize() {
    std::cout << "Please input width:";
    std::cin >> width;
    checkCommand(width);
    std::cout << "Please input height:";
    std::cin >> height;
    checkCommand(height);
}

void commandReader::readStep() {
    char c;
    std::cout << "Please input player's movement direction (L,U,R,D,E):";
    std::cin >> c;
    switch (c){
        case 'L':
            step = Player::LEFT;
            break;
        case 'U':
            step = Player::UP;
            break;
        case 'R':
            step = Player::RIGHT;
            break;
        case 'D':
            step = Player::DOWN;
            break;
        case 'E':
            step = Player::EXIT;
            break;
        default:
            step = Player::STOP;
            break;
    }
}

void commandReader::checkCommand(int &arg) {
    if (arg <= 0) {
        std::cout << "You've enetered wrong value. A standard value will be assigned.\n";
        arg = 10;
    }
}

void commandReader::readChar() {
    std::cout << "Please enter 'y' if you want to leave standard value(10, 10):";
    std::cin >> choice;
}

char commandReader::getChar() const{
    return choice;
}

int commandReader::getWidth() const{
    return width;
}

int commandReader::getHeight() const{
    return height;
}

Player::Step commandReader::getStep() const{
    return step;
}
