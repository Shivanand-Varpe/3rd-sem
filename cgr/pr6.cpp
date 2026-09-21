#include <graphics.h>
#include<stdio.h>
#include <conio.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor;

    if (x < 0 || x > getmaxx() || y < 0 || y > getmaxy())
        return;

    currentColor = getpixel(x, y);
    if (currentColor == boundaryColor || currentColor == fillColor)
        return;

    putpixel(x, y, fillColor);

    boundaryFill(x + 1, y, fillColor, boundaryColor);
    boundaryFill(x - 1, y, fillColor, boundaryColor);
    boundaryFill(x, y + 1, fillColor, boundaryColor);
    boundaryFill(x, y - 1, fillColor, boundaryColor);
}

int main() {
    int gd = DETECT, gm;
    int boundaryColor = WHITE;
    int fillColor = RED;
    int seedX = 200, seedY = 150;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(boundaryColor);
    line(120, 100, 280, 100);
    line(280, 100, 320, 200);
    line(320, 200, 200, 260);
    line(200, 260, 80, 200);
    line(80, 200, 120, 100);

    boundaryFill(seedX, seedY, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}