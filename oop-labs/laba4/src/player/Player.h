#ifndef LABA1_PLAYER_H
#define LABA1_PLAYER_H
#include "../log/Message.h"
#include "../log/LogPool.h"

class Player {

private:
    int health;
    int keys;
    int protection;

public:
    enum Step{UP, DOWN, LEFT, RIGHT, EXIT, STOP};
    void setHealth(int health);
    int getHealth();
    void setKeys(int keys);
    int getKeys();
    void setProtection(int protection);
    int getProtection();
    explicit Player(int health=1, int keys=0, int protection=1);
};
#endif//LABA1_PLAYER_H
