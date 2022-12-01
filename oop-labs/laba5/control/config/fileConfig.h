#ifndef LABA1_FILECONFIG_H
#define LABA1_FILECONFIG_H
#include "interfaceConfig.h"
#include <string>
#include <sstream>

class fileConfig : public interfaceConfig {
private:
    std::ifstream file;
public:
    explicit fileConfig(const std::string& fileName = "config.txt");
    ~fileConfig() override;
    std::map<char, Player::Step> getConfig() override;
};


#endif//LABA1_FILECONFIG_H
