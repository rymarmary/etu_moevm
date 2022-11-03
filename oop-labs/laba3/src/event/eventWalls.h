#ifndef LABA1_EVENTWALLS_H
#define LABA1_EVENTWALLS_H
#include "../event/eventField.h"
#include "../field/field.h"


class eventWalls: public eventField {
public:
    explicit eventWalls(Field* field);
    void execute() override;
};


#endif//LABA1_EVENTWALLS_H
