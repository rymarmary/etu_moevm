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
        Message message = Message(Levels::ERROR, "Incorrect data input");
        LogPool::getInstance()->print(&message);

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

void commandReader::printDeath() const {
    std::cout << "U're dead\n";
    Message message = Message(Levels::STATUS, "Player is dead");
    LogPool::getInstance()->print(&message);
}

void commandReader::printWin() const {
    std::cout << "U've won\n";
    Message message = Message(Levels::STATUS, "Player has won");
    LogPool::getInstance()->print(&message);
}

Player::Step commandReader::getStep() const{
    return step;
}

std::vector<std::string> commandReader::readLevels() {
    std::vector<std::string> levels;
    std::string answer;
    // for errors
    std::cout << "Do u want to Log Errors?\n";
    std::cin >> answer;
    if (answer != "yes") return levels;
    levels.push_back("error");
    // for status
    std::cout << "Do u want to Log Status?\n";
    std::cin >> answer;
    if (answer != "yes") return levels;
    levels.push_back("status");
    // for game
    std::cout << "Do u want to Log Game?\n";
    std::cin >> answer;
    if (answer != "yes") return levels;
    levels.push_back("game");
    return levels;
}

std::vector<std::string> commandReader::readLoggers() {
    std::vector<std::string> loggers;
    std::string answer;
    std::cout << "Do u want to Output Messages in Console?\n";
    std::cin >> answer;
    if (answer == "yes") loggers.push_back("console");
    std::cout << "Do u want to Output Messages in File?\n";
    std::cin >> answer;
    if (answer == "yes") loggers.push_back("file");
    return loggers;
}
