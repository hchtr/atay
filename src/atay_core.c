#include "win32_helpers.h"
#include "atay_rasterizer.h"

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

		atay_draw_line(&global_backbuffer, 0, 0, width, height, 0xFFFFFF);
		atay_draw_line(&global_backbuffer, width, 0, 0, height, 0xFFFFFF);

		HDC hdc = GetDC(window);
        StretchDIBits(
            hdc,
            0, 0, width, height,
			0, 0, width, height, 
			global_backbuffer.memory,
            &global_bitmap_info,
            DIB_RGB_COLORS,
            SRCCOPY
        );
        ReleaseDC(window, hdc);
	}

	ExitProcess(0);
}
