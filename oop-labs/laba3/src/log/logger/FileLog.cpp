#include <fstream>
#include "FileLog.h"
#include <iostream>

FileLog::FileLog(){
    this->file.open("logs.txt", std::ofstream::out | std::ofstream::trunc);
}


FileLog::~FileLog() {
    this->file.close();
}


void FileLog::logOutput(Message* message) {
    if (file.is_open()) file << *message << '\n';
}
