#include "logger.h"

void start() {
    initConsole();

    logConsole(LOG_WARNING, "test4\n");

    ExitProcess(0);
}
