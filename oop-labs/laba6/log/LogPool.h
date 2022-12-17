#ifndef LABA1_LOGPOOL_H
#define LABA1_LOGPOOL_H
#include "vector"
#include "logger/logger.h"
#include <cstring>
#include "logger/ConsoleLog.h"
#include "logger/FileLog.h"

class LogPool {
private:
    std::vector<Logger*> arrLoggers;
    std::map<Levels,bool> levelLogging{
            {Levels::GAME, false},
            {Levels::STATUS, false},
            {Levels::ERROR, false}
    };
    static LogPool* instance; // для singleton
public:
    void print(Message*);
    void setLoggers(std::vector<std::string>);
    void setLevels(std::vector<std::string>);
    static LogPool* getInstance();  // для singleton
    void deleteLoggers();
    void deleteInstance();
};


#endif//LABA1_LOGPOOL_H
