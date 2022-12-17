#ifndef LABA1_OPENFILEEXCEPTION_H
#define LABA1_OPENFILEEXCEPTION_H
#include "GameException.h"


class OpenFileException: public GameException{
public:
    using GameException::GameException;
    std::string what() final;
};


#endif//LABA1_OPENFILEEXCEPTION_H
