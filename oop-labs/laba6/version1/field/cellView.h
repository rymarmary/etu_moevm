#ifndef LABA1_CELLVIEW_H
#define LABA1_CELLVIEW_H
#include "../field/field.h"

class cellView {

private:
    char option;

public:
    explicit cellView(Cell cell);
    char getOption() const;
};


#endif//LABA1_CELLVIEW_H
