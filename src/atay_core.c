#include "win32_helpers.h"

int start() {
	HWND window = win32_init_window(1280, 720, "Atay Engine");
	
	if(!window) return -1;

	while (win32_is_running()) {
		win32_process_messages();
	}

	ExitProcess(0);
}
