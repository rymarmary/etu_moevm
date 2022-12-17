#ifndef LABA1_LEVELCONTEXT_H
#define LABA1_LEVELCONTEXT_H
#include "memory"
#include "levelStrategy.h"


class levelContext {
private:
    Field* field;
    levelStrategy* level;
public:
    explicit levelContext(levelStrategy* strategy = nullptr);
    void setStrategy(levelStrategy* strategy);
    void setLevel();
    Field* getField();
    ~levelContext();
};


#endif//LABA1_LEVELCONTEXT_H
