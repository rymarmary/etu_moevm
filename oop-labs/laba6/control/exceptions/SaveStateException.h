#ifndef LABA1_SAVESTATEEXCEPTION_H
#define LABA1_SAVESTATEEXCEPTION_H
#include "GameException.h"


class SaveStateException: public GameException {
public:
    using GameException::GameException;
    std::string what() final;
};


#endif//LABA1_SAVESTATEEXCEPTION_H
