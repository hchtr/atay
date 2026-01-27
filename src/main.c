#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_WARNING, "test3\n");

    ExitProcess(0);
}
