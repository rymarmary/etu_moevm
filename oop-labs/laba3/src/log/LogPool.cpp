#include "LogPool.h"

LogPool *LogPool::instance = nullptr;

void LogPool::print(Message* message) {
    if (levelLogging.at(message->getLevel())){
        for (auto i:arrLoggers){
            i->logOutput(message);
        }
    }
}


void LogPool::setLevels(std::vector<std::string> level) {
    for (auto i:level){
        if (i == "game") levelLogging.at(Levels::GAME) = true;
        if (i == "status") levelLogging.at(Levels::STATUS) = true;
        if (i == "error") levelLogging.at(Levels::ERROR) = true;
    }
}


void LogPool::setLoggers(std::vector<std::string> loggers) {
    for (auto i:loggers){
        if (i == "console") arrLoggers.push_back(new ConsoleLog);
        if (i == "file") arrLoggers.push_back(new FileLog);
    }
}


LogPool *LogPool::getInstance() {   // singleton
    if (instance == nullptr){
        instance = new LogPool;
    }
    return instance;
}


void LogPool::deleteLoggers() {
    for (auto i:arrLoggers) delete i;
}


void LogPool::deleteInstance() {
    delete instance;
}
