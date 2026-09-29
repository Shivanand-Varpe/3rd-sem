#include <graphics.h>
#include <conio.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Point3D;

void projectPoint(Point3D point, int originX, int originY,
                  int *screenX, int *screenY) {
    *screenX = originX + (int)(point.x - point.z * 0.5f);
    *screenY = originY - (int)(point.y - point.z * 0.5f);
}

void drawCuboid(Point3D points[8], int originX, int originY, int color) {
    int screenX[8];
    int screenY[8];
    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };
    int i;

    setcolor(color);
    for (i = 0; i < 8; i++)
        projectPoint(points[i], originX, originY, &screenX[i], &screenY[i]);

    for (i = 0; i < 12; i++)
        line(screenX[edges[i][0]], screenY[edges[i][0]],
             screenX[edges[i][1]], screenY[edges[i][1]]);
}

void transformCuboid(Point3D source[8], Point3D transformed[8],
                     float sx, float sy, float sz,
                     float tx, float ty, float tz) {
    int i;

    for (i = 0; i < 8; i++) {
        transformed[i].x = source[i].x * sx + tx;
        transformed[i].y = source[i].y * sy + ty;
        transformed[i].z = source[i].z * sz + tz;
    }
}

int main() {
    int gd = DETECT, gm;
    float sx, sy, sz, tx, ty, tz;
    Point3D original[8] = {
        {0, 0, 0}, {80, 0, 0}, {80, 60, 0}, {0, 60, 0},
        {0, 0, 50}, {80, 0, 50}, {80, 60, 50}, {0, 60, 50}
    };
    Point3D transformed[8];

    printf("Enter scaling factors (sx sy sz): ");
    scanf("%f %f %f", &sx, &sy, &sz);
    printf("Enter translation values (tx ty tz): ");
    scanf("%f %f %f", &tx, &ty, &tz);

    transformCuboid(original, transformed, sx, sy, sz, tx, ty, tz);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    drawCuboid(original, 180, 260, WHITE);
    outtextxy(115, 300, "Original Cuboid");

    drawCuboid(transformed, 500, 260, LIGHTGREEN);
    outtextxy(420, 300, "Scaled and Translated Cuboid");

    getch();
    closegraph();
    return 0;
}
