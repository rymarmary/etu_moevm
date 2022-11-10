#ifndef LABA1_CHREADER_H
#define LABA1_CHREADER_H
#include "interfaceChReader.h"
#include <iostream>

class ChReader : public interfaceChReader {
public:
    char getChar() override;
};


#endif//LABA1_CHREADER_H
