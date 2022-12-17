#ifndef LABA1_INVALIDDATAEXCEPTION_H
#define LABA1_INVALIDDATAEXCEPTION_H
#include "GameException.h"

class InvalidDataException: public GameException {
public:
    using GameException::GameException;
    std::string what() final;
};


#endif//LABA1_INVALIDDATAEXCEPTION_H
