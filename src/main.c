#include <windows.h>

void start() {
    
    char buffer[] = "Hello, World!";

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;

    WriteFile(hOut, buffer, sizeof(buffer), &written, 0);

    ExitProcess(0);
}
