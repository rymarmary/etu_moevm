#ifndef LABA1_FIELDVIEW_H
#define LABA1_FIELDVIEW_H
class Field;
#include "cellView.h"

class fieldView {

private:
    Field* field;

public:
    explicit fieldView(Field *field);
    void printField();
};


#endif//LABA1_FIELDVIEW_H
