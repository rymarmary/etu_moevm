#ifndef LABA1_LEVELSTRATEGY_H
#define LABA1_LEVELSTRATEGY_H
#include "../../field/field.h"

class levelStrategy{
public:
    virtual Field* generateLevel() = 0;
    virtual ~levelStrategy() = default;
};

#endif//LABA1_LEVELSTRATEGY_H
