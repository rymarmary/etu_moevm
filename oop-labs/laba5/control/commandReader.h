#ifndef LABA1_COMMANDREADER_H
#define LABA1_COMMANDREADER_H
#include "../player/Player.h"
#include <iostream>
#include <vector>
#include "commands/ChReader.h"
#include "config/fileConfig.h"

class commandReader {

private:
    int width, height;
    char choice;
    Player::Step step;
    interfaceChReader* command;

public:
    void readSize();
    void readStep(const std::map<char, Player::Step>&);
    void checkCommand(int &arg);
    int getWidth() const;
    int getHeight() const;
    char getChar() const;
    char getLevel() const;
    void readChar();
    void printDeath() const;
    void printWin() const;
    Player::Step getStep() const;
    std::vector<std::string> readLevels();
    std::vector<std::string> readLoggers();
    ~commandReader();
    char readConfig();
    void getSrc();
};


#endif//LABA1_COMMANDREADER_H
