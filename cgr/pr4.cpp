#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 3 - 2 * r;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (p < 0) {
            p += 4 * x + 6;
        } else {
            p += 4 * (x - y) + 10;
            y--;}
        x++;}}
int main() {
    int gd = DETECT, gm;
    int xc, yc, r;
    printf("Enter circle center coordinates (xc yc): ");
    if (scanf("%d %d", &xc, &yc) != 2) {
        printf("Invalid input.\n");
        return 1;}
    printf("Enter radius: ");
    if (scanf("%d", &r) != 1 || r <= 0) {
        printf("Invalid radius.\n");
        return 1;}
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawCircle(xc, yc, r);
    getch();
    closegraph();
    return 0;}
