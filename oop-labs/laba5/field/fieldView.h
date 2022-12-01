#ifndef LABA1_FIELDVIEW_H
#define LABA1_FIELDVIEW_H

#include "cellView.h"
#include "field.h"

class fieldView {

private:
    Field* field;

public:
    explicit fieldView(Field *field);
    void printField();
};


#endif//LABA1_FIELDVIEW_H
