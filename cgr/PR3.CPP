#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
void bresenham(int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y, k, sx, sy;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = (x2 >= x1) ? 1 : -1;
    sy = (y2 >= y1) ? 1 : -1;
    x = x1,y = y1;
    if (dx >= dy) {
        p = 2 * dy - dx;
        for (k = 0; k <= dx; k++) {
            putpixel(x, y, WHITE);
            if (p < 0) {
                p += 2 * dy;
            } else {
                p += 2 * (dy - dx);
                y += sy;}
            x += sx;}}
     else {
        p = 2 * dx - dy;
        for (k = 0; k <= dy; k++) {
            putpixel(x, y, WHITE);
            if (p < 0) {
                p += 2 * dx;} else {
                p += 2 * (dx - dy);
                x += sx;}
            y += sy;}}}
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    printf("Enter the starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    bresenham(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;}