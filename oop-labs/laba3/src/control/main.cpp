#include "mediator.h"

int main() {
    Mediator().start();
    LogPool::getInstance()->deleteLoggers();
    return 0;
}
