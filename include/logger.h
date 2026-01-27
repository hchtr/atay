#include <windows.h>

typedef enum LogLevel {
    LOG_INFO,
    LOG_ERROR,
    LOG_WARNING
} LogLevel;

void initConsole();

static DWORD cstrlen(const char *s);

void setColor(WORD color);

void resetColor();

void printConsole(const char *buffer);

void logConsole(LogLevel level, const char *buffer);
