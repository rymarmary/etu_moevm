#ifndef LABA1_RESTORESTATEEXCEPTION_H
#define LABA1_RESTORESTATEEXCEPTION_H
#include "GameException.h"


class RestoreStateException: public GameException {
public:
    using GameException::GameException;
    std::string what() final;
};


#endif//LABA1_RESTORESTATEEXCEPTION_H
