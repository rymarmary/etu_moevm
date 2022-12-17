#ifndef LABA1_MEMENTO_H
#define LABA1_MEMENTO_H
#include <string>
#include <fstream>

class Memento {
public:
    void saveState(std::string, std::string);
    std::string restoreState(std::string);
};


#endif//LABA1_MEMENTO_H
