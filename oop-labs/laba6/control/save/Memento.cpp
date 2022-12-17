#include <iostream>
#include "Memento.h"


void Memento::saveState(std::string state, std::string fileName) {
    std::fstream fileSave;
    fileSave.open(fileName, std::ios::out);
    if (!fileSave.is_open())
        throw OpenFileException("Failed to open the file " + fileName + " for saving");
    fileSave << state;
    fileSave.close();
}


std::string Memento::restoreState(std::string fileName) {
    std::fstream fileSave;
    fileSave.open(fileName);
    if (!fileSave.is_open())
        throw OpenFileException("Failed to open the file " + fileName + " for restoring");
    std::string data;
    std::string line;
    while (getline(fileSave, line)){
        data += line;
        data += '\n';
    }
    return data;
}
