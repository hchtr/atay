#ifndef WIN32_HELPERS_H
#define WIN32_HELPERS_H

#include <windows.h>

HWND win32_init_window(int width, int height, const char* title);
int win32_is_running(void);
void win32_process_messages(void);
void win32_init_buffer(int width, int height);

#endif
