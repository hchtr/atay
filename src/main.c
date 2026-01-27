#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_WARNING, "test\n");

    ExitProcess(0);
}
