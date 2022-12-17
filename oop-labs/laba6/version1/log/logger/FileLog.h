#ifndef LABA1_FILELOG_H
#define LABA1_FILELOG_H
#include "logger.h"
#include <fstream>

class FileLog: public Logger{
private:
    std::ofstream file;
public:
    void logOutput(Message*) override;
    FileLog();
    ~FileLog() override;
};


#endif//LABA1_FILELOG_H
