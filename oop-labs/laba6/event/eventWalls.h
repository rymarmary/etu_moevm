#ifndef LABA1_EVENTWALLS_H
#define LABA1_EVENTWALLS_H
#include "../event/eventField.h"


class eventWalls: public eventField {
private:
    size_t hash;
public:
    explicit eventWalls(Field* field);
    void execute() override;
    size_t getHash() final;
};


#endif//LABA1_EVENTWALLS_H
