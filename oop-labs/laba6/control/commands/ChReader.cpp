#include "ChReader.h"


char ChReader::getChar() {
    char c;
    std::cout << "Please input player's movement direction (l,u,r,d,e):";
    std::cin >> c;
    return c;
}
