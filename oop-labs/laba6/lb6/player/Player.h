#ifndef LABA1_PLAYER_H
#define LABA1_PLAYER_H
#include "../log/Message.h"
#include "../log/LogPool.h"
#include "../control/save/Originator.h"
#include <sstream>
#define TOTALVAL 3

class Player:public Originator {

private:
    int health;
    int keys;
    int protection;
    size_t hash(int keys, int health, int protection);
    std::vector<int> restoredData;

public:
    enum Step{UP, DOWN, LEFT, RIGHT, EXIT, STOP, LOAD, RESTORE};
    void setHealth(int health);
    int getHealth();
    void setKeys(int keys);
    int getKeys();
    void setProtection(int protection);
    int getProtection();
    explicit Player(int health=1, int keys=0, int protection=1);
    std::string getState();
    void setState(std::string);
    void restoreState();
};
#endif//LABA1_PLAYER_H
