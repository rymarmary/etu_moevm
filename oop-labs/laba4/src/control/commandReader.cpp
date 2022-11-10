#include "commandReader.h"

void commandReader::readSize() {
    std::cout << "Please input width:";
    std::cin >> width;
    checkCommand(width);
    std::cout << "Please input height:";
    std::cin >> height;
    checkCommand(height);
}

void commandReader::readStep(const std::map<char, Player::Step> &config){
    auto elem = config.find(command->getChar());
    if (elem != config.end()) {
        step = elem->second;
        return;
    }
    if (elem == config.end()) {
        step = Player::Step::STOP;
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
    levels.emplace_back("error");
    // for status
    std::cout << "Do u want to Log Status?\n";
    std::cin >> answer;
    if (answer != "yes") return levels;
    levels.emplace_back("status");
    // for game
    std::cout << "Do u want to Log Game?\n";
    std::cin >> answer;
    if (answer != "yes") return levels;
    levels.emplace_back("game");
    return levels;
}

std::vector<std::string> commandReader::readLoggers() {
    std::vector<std::string> loggers;
    std::string answer;
    std::cout << "Do u want to Output Messages in Console?\n";
    std::cin >> answer;
    if (answer == "yes") loggers.emplace_back("console");
    std::cout << "Do u want to Output Messages in File?\n";
    std::cin >> answer;
    if (answer == "yes") loggers.emplace_back("file");
    return loggers;
}


commandReader::~commandReader() {
    delete command;
}


char commandReader::readConfig() {
    char c;
    std::cout << "Do u want to leave default settings? (u,d,r,l,e) \n";
    std::cin >> c;
    return c;
}

void commandReader::getSrc() {
    char ch;
    std::cout << "Where will the control be read from? Any character is from the console.";
    std::cin >> ch;
    if (ch) command = new ChReader;
}

