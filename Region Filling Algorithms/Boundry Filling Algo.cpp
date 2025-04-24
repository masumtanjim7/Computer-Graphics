#include <graphics.h>
#include <conio.h>
#include <math.h>

// 4-connected Boundary Fill algorithm
void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current = getpixel(x, y);
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Flag boundaries
    int left = 100, top = 100;
    int right = 460, bottom = 280;

    // Draw flag rectangle
    setcolor(WHITE); // Boundary color
    rectangle(left, top, right, bottom);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill((left + right) / 2, (top + bottom) / 2, WHITE); // Fill green background

    // Circle (sun)
    int circle_x = left + (int)((right - left) * 0.45); // slightly left from center
    int circle_y = (top + bottom) / 2;
    int radius = 45;

    setcolor(WHITE); // Circle boundary color
    circle(circle_x, circle_y, radius);

    // Fill red inside circle using Boundary Fill
    boundaryFill(circle_x, circle_y, RED, WHITE);

    getch();
    closegraph();
    return 0;
}

