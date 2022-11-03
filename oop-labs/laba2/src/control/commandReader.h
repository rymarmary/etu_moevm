#ifndef LABA1_COMMANDREADER_H
#define LABA1_COMMANDREADER_H
#include "../player/Player.h"
#include <iostream>

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
};


#endif//LABA1_COMMANDREADER_H
