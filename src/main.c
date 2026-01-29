#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_INFO, "test5\n");

    ExitProcess(0);
}
