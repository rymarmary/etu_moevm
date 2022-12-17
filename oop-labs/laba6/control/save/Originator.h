#ifndef LABA1_ORIGINATOR_H
#define LABA1_ORIGINATOR_H
#include <string>


class Originator {
    virtual std::string getState() = 0;
    virtual void setState(std::string) = 0;
};


#endif//LABA1_ORIGINATOR_H
