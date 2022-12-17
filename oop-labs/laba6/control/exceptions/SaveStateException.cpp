#include "SaveStateException.h"


std::string SaveStateException::what() {
    return "Failed to save state: " + message;
}
