#include <iostream>
#include<graphics.h>
#include<math.h>
#include<windows.h>
using namespace std;

void midPoint(int x1,int y1,int x2, int y2){

    int x_max = getmaxx();
    int y_max = getmaxy();

    setcolor(RED);
    line(0,y_max/2,x_max,y_max/2);
    setcolor(RED);
    line(x_max/2,0,x_max/2,y_max);
    int x,y,dx,dy;
    float d,dr,dl;
    dx = x2-x1;
    dy =y2-y1;
    d = (2*dy) - dx;
    dr = 2*dy;
    dl = 2*(dy-dx);

    x = x1 + x_max/2;
    y = y1 + y_max/2;

    while(x<=x2+x_max/2){
        putpixel(x,y,GREEN);
        if(d>=0){
            x++;
            d += dr;
        }
        else{
            x++;
            y++;
            d += dl;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    initgraph(&gd, &gm,"");

    midPoint(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}
