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

    // Flag ratio: 10(width):6(height)
    int flag_width = 300;
    int flag_height = flag_width * 6 / 10;

    int left = 200, top = 100;
    int right = left + flag_width;
    int bottom = top + flag_height;

    // Draw the flag rectangle (green background)
    setcolor(WHITE);  // boundary color
    rectangle(left, top, right, bottom);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill((left + right) / 2, (top + bottom) / 2, WHITE);

    // Draw the red circle (sun) — offset to the hoist
    int circle_radius = flag_height / 3;
    int circle_x = left + flag_width * 0.45;  // 45% from left
    int circle_y = (top + bottom) / 2;

    setcolor(WHITE);  // boundary color for circle
    circle(circle_x, circle_y, circle_radius);
    boundaryFill(circle_x, circle_y, RED, WHITE);

    // Add black flagpole
    int pole_x = left - 20;
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(pole_x, top - 50, pole_x, bottom + 120); // vertical pole

    // Base of the stand
    rectangle(pole_x - 30, bottom + 120, pole_x + 30, bottom + 140);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(pole_x, bottom + 130, WHITE);

    // Attach flag to the pole
    line(pole_x, top, left, top);
    line(pole_x, bottom, left, bottom);

    getch();
    closegraph();
    return 0;
}
