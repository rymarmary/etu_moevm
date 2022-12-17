#ifndef LABA1_FIELDSIZE_H
#define LABA1_FIELDSIZE_H
#include "../../field/field.h"

template<int x=10, int y=10>
class fieldSize{
public:
    void operator()(Field* field){
        if (x<10 || x>30 || y<10 || y>30) return;
        delete field;
        field = new Field(x, y);
    }
};

#endif//LABA1_FIELDSIZE_H
