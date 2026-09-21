#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
                  int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translateTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
                       int tx, int ty, int &newX1, int &newY1,
                       int &newX2, int &newY2, int &newX3, int &newY3) {
    newX1 = x1 + tx;
    newY1 = y1 + ty;
    newX2 = x2 + tx;
    newY2 = y2 + ty;
    newX3 = x3 + tx;
    newY3 = y3 + ty;
}

int main() {
    int gd = DETECT, gm;
    int tx, ty;
    int originalX1 = 80, originalY1 = 120;
    int originalX2 = 150, originalY2 = 120;
    int originalX3 = 115, originalY3 = 190;
    int scaledX1 = 280, scaledY1 = 110;
    int scaledX2 = 385, scaledY2 = 110;
    int scaledX3 = 332, scaledY3 = 215;
    int translatedX1, translatedY1;
    int translatedX2, translatedY2;
    int translatedX3, translatedY3;

    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);
    translateTriangle(originalX1, originalY1, originalX2, originalY2,
                      originalX3, originalY3, tx, ty,
                      translatedX1, translatedY1, translatedX2, translatedY2,
                      translatedX3, translatedY3);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    drawTriangle(originalX1, originalY1, originalX2, originalY2,
                 originalX3, originalY3, WHITE);
    outtextxy(80, 200, "Original Object");

    drawTriangle(scaledX1, scaledY1, scaledX2, scaledY2,
                 scaledX3, scaledY3, YELLOW);
    outtextxy(280, 225, "Scaled Object");

    drawTriangle(translatedX1, translatedY1, translatedX2, translatedY2,
                 translatedX3, translatedY3, LIGHTGREEN);
    outtextxy(translatedX1, translatedY1 + 15, "Translated Object");

    printf("\n1. Original Object");
    printf("\n2. Scaled Object (1.5 times larger)");
    printf("\n3. Translated Object");

    getch();
    closegraph();
    return 0;
}
