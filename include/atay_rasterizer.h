#ifndef ATAY_RASTERIZER_H
#define ATAY_RASTERIZER_H

#include <windows.h>

typedef struct {
    unsigned int* memory;
    int width;
    int height;
} PixelBuffer;

void atay_draw_line(PixelBuffer* buffer, int x0, int y0, int x1, int y1, unsigned int color);
void atay_clear_screen(PixelBuffer* buffer, unsigned int color); 

extern PixelBuffer global_backbuffer;
extern BITMAPINFO global_bitmap_info;

#endif
