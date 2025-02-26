#include <iostream>
#include<graphics.h>
#include<math.h>
#include<windows.h>

using namespace std;

// Bresenhum line Drawing algorithm;

void brasenhumn(int x1,int y1, int x2, int y2){

    int x_max = getmaxx();
    int y_max = getmaxy();

    setcolor(RED);
    line(0,y_max/2,x_max,y_max/2);
    setcolor(RED);
    line(x_max/2,0,x_max/2,y_max);
    int x,y,dx,dy;
    float d,ds,dt;
    dx = x2-x1;
    dy =y2-y1;
    d = (2*dy) - dx;
    ds = 2*dy;
    dt = 2*(dy-dx);

    x = x1 + x_max/2;
    y = y1 + y_max/2;

    while(x<=x2+x_max/2){
        putpixel(x,y,GREEN);
        if(d<0){
            x++;
            d +=ds;
        }else{
            x++;
            y--;
            d +=dt;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    initgraph(&gd, &gm, "");

    brasenhumn(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}
