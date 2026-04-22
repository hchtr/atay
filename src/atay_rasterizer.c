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


void atay_draw_hline(PixelBuffer* buffer, int x1, int x2, int y, unsigned int color) {
    if (y < 0 || y >= buffer->height) return;
    if (x1 > x2) { int t = x1; x1 = x2; x2 = t; }
    
    if (x1 < 0) x1 = 0;
    if (x2 >= buffer->width) x2 = buffer->width - 1;

    for (int x = x1; x <= x2; x++) {
        buffer->memory[y * buffer->width + x] = color;
    }
}

void fill_flat_bottom(PixelBuffer* buffer, int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color) {
    float invslope1 = (float)(x1 - x0) / (y1 - y0);
    float invslope2 = (float)(x2 - x0) / (y2 - y0);

    float curx1 = x0;
    float curx2 = x0;

    for (int scanlineY = y0; scanlineY <= y1; scanlineY++) {
        atay_draw_hline(buffer, (int)curx1, (int)curx2, scanlineY, color);
        curx1 += invslope1;
        curx2 += invslope2;
    }
}

void fill_flat_top(PixelBuffer* buffer, int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color) {
    float invslope1 = (float)(x2 - x0) / (y2 - y0);
    float invslope2 = (float)(x2 - x1) / (y2 - y1);

    float curx1 = x2;
    float curx2 = x2;

    for (int scanlineY = y2; scanlineY > y0; scanlineY--) {
        atay_draw_hline(buffer, (int)curx1, (int)curx2, scanlineY, color);
        curx1 -= invslope1;
        curx2 -= invslope2;
    }
}

void atay_fill_triangle(PixelBuffer* buffer, int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color) {
    if (y0 > y1) { int tx = x0; x0 = x1; x1 = tx; int ty = y0; y0 = y1; y1 = ty; }
    if (y0 > y2) { int tx = x0; x0 = x2; x2 = tx; int ty = y0; y0 = y2; y2 = ty; }
    if (y1 > y2) { int tx = x1; x1 = x2; x2 = tx; int ty = y1; y1 = y2; y2 = ty; }

    if (y1 == y2) {
        fill_flat_bottom(buffer, x0, y0, x1, y1, x2, y2, color);
    } else if (y0 == y1) {
        fill_flat_top(buffer, x0, y0, x1, y1, x2, y2, color);
    } else {
        int x3 = (int)(x0 + ((float)(y1 - y0) / (float)(y2 - y0)) * (x2 - x0));
        
        fill_flat_bottom(buffer, x0, y0, x1, y1, x3, y1, color);
        fill_flat_top(buffer, x1, y1, x3, y1, x2, y2, color);
    }
    
    atay_draw_line(buffer, x0, y0, x1, y1, color);
    atay_draw_line(buffer, x1, y1, x2, y2, color);
    atay_draw_line(buffer, x2, y2, x0, y0, color);
}
