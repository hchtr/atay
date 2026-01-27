#include <windows.h>
#include "logger.h"

static HANDLE hOut;

void initConsole() {
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

static DWORD cstrlen(const char *s) {
    DWORD n = 0;
    while (s[n]) n++;
    return n;
}

void setColor(WORD color) {
    SetConsoleTextAttribute(hOut, color);
}

void resetColor() {
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
}

void printConsole(const char *buffer) {
    DWORD written;
    WriteFile(hOut, buffer, cstrlen(buffer), &written, 0);
}

void logConsole(LogLevel level, const char *buffer) {
    switch(level) {
        case LOG_INFO:
            setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            printConsole("[INFO]: ");
            resetColor();
            printConsole(buffer);
            break;
        case LOG_WARNING:
            setColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            printConsole("[WARNING]: ");
            resetColor();
            printConsole(buffer);
            break;
        case LOG_ERROR:
            setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
            printConsole("[ERROR]: ");
            resetColor();
            printConsole(buffer);
            break; 
    }
}

