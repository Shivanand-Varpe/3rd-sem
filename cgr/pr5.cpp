#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void floodFill(int x, int y, int oldColor, int newColor) {
    if (x < 0 || x > getmaxx() || y < 0 || y > getmaxy())
        return;
    int currentColor = getpixel(x, y);
    if (currentColor != oldColor || currentColor == newColor)
        return;
    putpixel(x, y, newColor);
    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);}
int main() {
    int gd = DETECT, gm;
    int seedX = 200, seedY = 140;
    int fillColor = 4;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(120, 100, 280, 100);
    line(280, 100, 200, 220); 
    line(200, 220, 120, 100); 
    int oldColor = getpixel(seedX, seedY);
    floodFill(seedX, seedY, oldColor, fillColor);
    getch();
    closegraph();
    return 0;}
