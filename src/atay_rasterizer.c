#include <intrin.h>
#include "atay_rasterizer.h"

void atay_draw_line(PixelBuffer* buffer, int x0, int y0, int x1, int y1, unsigned int color) {
    int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
    int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x0 >= 0 && x0 < buffer->width && y0 >= 0 && y0 < buffer->height) {
            buffer->memory[y0 * buffer->width + x0] = color;
        }
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx)  { err += dx; y0 += sy; }
    }
}

void atay_clear_screen(PixelBuffer* buffer, unsigned int color) {
    __stosd((unsigned long*)buffer->memory, 
            (unsigned long)color, 
            (unsigned long)(buffer->width * buffer->height));
}
