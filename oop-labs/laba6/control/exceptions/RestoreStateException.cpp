#include "RestoreStateException.h"


std::string RestoreStateException::what() {
    return "Failed to restore state: " + message;
}
