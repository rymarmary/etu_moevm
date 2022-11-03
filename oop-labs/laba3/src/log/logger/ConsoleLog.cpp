#include "ConsoleLog.h"

void ConsoleLog::logOutput(Message* mes) {
    std::cout << *mes << '\n';
}
