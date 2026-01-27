#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_WARNING, "test2\n");

    ExitProcess(0);
}
