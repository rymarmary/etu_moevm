#ifndef LABA1_GAMEEXCEPTION_H
#define LABA1_GAMEEXCEPTION_H
#include <exception>
#include <string>


class GameException: public std::exception{
protected:
    std::string message;
public:
    GameException(std::string);
    virtual std::string what() = 0;
};


#endif//LABA1_GAMEEXCEPTION_H
