#include "OpenFileException.h"

std::string OpenFileException::what() {
    return "Failed to open the file: " + message;
}
