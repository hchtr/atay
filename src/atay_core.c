#include "win32_helpers.h"
#include "atay_rasterizer.h"

int _fltused = 0;

extern PixelBuffer global_backbuffer;
extern BITMAPINFO global_bitmap_info;

int start() {

	int width = 1280;
	int height = 720;

	HWND window = win32_init_window(width, height, "Atay Engine");
	win32_init_buffer(width, height);

	if(!window) ExitProcess(-1);

	while (win32_is_running()) {
		win32_process_messages();

		atay_clear_screen(&global_backbuffer, 0x000000);
		atay_draw_line(&global_backbuffer, 0, height / 2, width, height / 2, 0xFEAF00);
		atay_draw_line(&global_backbuffer, width / 2, 0, width / 2, height, 0xFFEA00);
		
		atay_fill_triangle(&global_backbuffer, 100, 100, 300, 300, 150, 450, 0x0000FF);

		win32_display_buffer(width, height, window);
	}

	ExitProcess(0);
}
