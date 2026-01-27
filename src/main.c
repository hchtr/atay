#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_INFO, "Hello, World\n");

    ExitProcess(0);
}
