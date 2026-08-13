#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void dda(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, k;
    float x, y, x_inc, y_inc;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    x_inc = (float)dx / steps;
    y_inc = (float)dy / steps;

    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    for (k = 0; k < steps; k++) {
        x += x_inc;
        y += y_inc;
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    printf("Enter the starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dda(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}