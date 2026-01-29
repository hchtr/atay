#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_INFO, "Hi hchtr!\n");

    ExitProcess(0);
}
