#include <graphics.h>
#include <conio.h>
int main(){
    int gd = DETECT, gm;
    int tri[] = {500, 150, 550, 250, 450, 250};
    int poly[] = {100, 300, 150, 250, 220, 270, 200, 340, 120, 360};
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    putpixel(50, 50, WHITE);
    line(80, 80, 200, 80);
    circle(300, 100, 50);
    ellipse(450, 100, 0, 360, 70, 40);
    rectangle(80, 150, 200, 250);
    line(tri[0], tri[1], tri[2], tri[3]);
    line(tri[2], tri[3], tri[4], tri[5]);
    line(tri[4], tri[5], tri[0], tri[1]);
    getch();
    closegraph();
    return 0;}

    