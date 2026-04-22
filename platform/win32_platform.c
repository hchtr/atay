#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "win32_helpers.h"

static int global_running = 1;

LRESULT CALLBACK win32_window_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	LRESULT result = 0;
	switch (msg) {
		case WM_CLOSE:
		case WM_DESTROY: {
			global_running = 0;
		} break;
		
		default: {
			result = DefWindowProcA(hwnd, msg, wparam, lparam);
		} break;
	}
	return result;
}

HWND win32_init_window(int width, int height, const char* title) {
	HINSTANCE instance = GetModuleHandleA(NULL);

	WNDCLASS window_class = {0};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = win32_window_callback;
	window_class.hInstance = instance;
	window_class.lpszClassName = "AtayWindowClass";
	window_class.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!RegisterClassA(&window_class)) return NULL;

	return 
		CreateWindowExA(
			0,
			window_class.lpszClassName, title,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT, CW_USEDEFAULT, width, height,
			0, 0, instance, 0
		);
}

int win32_is_running(void) {
	return global_running;
}

void win32_process_messages(void) {
	MSG msg;
	while(PeekMessageA(&msg, 0, 0, 0, PM_REMOVE)) {		
		if (msg.message == WM_QUIT) global_running = 0;
			TranslateMessage(&msg);
			DispatchMessageA(&msg);			
	}
}

