#ifndef LABA1_MESSAGE_H
#define LABA1_MESSAGE_H
#include <string>
#include <map>
#include "Levels.h"
#include <ctime>
#include <ostream>
#include <utility>

class Message {
private:
    Levels level;
    std::string text;
    std::string timeMessage;
    std::map<Levels,std::string> levelsConverter{
            {Levels::GAME, "|game|"},
            {Levels::STATUS, "|status|"},
            {Levels::ERROR, "|error|"}
    };
public:
    Message(Levels level, std::string text);
    friend std::ostream& operator << (std::ostream&, Message&);
    Levels getLevel();
};


#endif//LABA1_MESSAGE_H
