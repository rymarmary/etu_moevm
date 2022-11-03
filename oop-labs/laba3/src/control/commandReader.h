#ifndef LABA1_COMMANDREADER_H
#define LABA1_COMMANDREADER_H
#include "../player/Player.h"
#include <iostream>
#include <vector>

class commandReader {

private:
    int width, height;
    char choice;
    Player::Step step;

public:
    void readSize();
    void readStep();
    void checkCommand(int &arg);
    int getWidth() const;
    int getHeight() const;
    char getChar() const;
    void readChar();
    void printDeath() const;
    void printWin() const;
    Player::Step getStep() const;
    std::vector<std::string> readLevels();
    std::vector<std::string> readLoggers();
};


#endif//LABA1_COMMANDREADER_H
