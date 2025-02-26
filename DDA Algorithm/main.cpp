#include <iostream>
#include<graphics.h>
#include<math.h>
#include<windows.h>
using namespace std;

// DDA Algorithm


void dda(int x1,int y1,int x2,int y2){
    int x,y;
    float dx,dy,m;
    dx = x2-x1;
    dy = y2-y1;
    m = dy/dx;

    int xx = getmaxx();
    int yy = getmaxy();

    setcolor(RED + BLUE);
    line(0,yy/2,xx,yy/2);

    setcolor(GREEN + RED);
    line(xx/2, 0, xx/2, yy);

    x = x1+xx/2, y = y1+yy/2;

    if(abs(m)<=1){
        while(x<=x2+xx/2){
            putpixel(x,y,RED);
            x++;
            y -=m;

        }
    }
    else{
        while(y<=(yy/2)-y2){
            putpixel(x,y,RED);
            y--;
            x +=(1/m);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1,y1,x2,y2;

    cout<<"Get the value of x1 and y1: ";
    cin>>x1>>y1;
    cout<<"Get the value of x2 and y2: ";
    cin>>x2>>y2;

   // int x = getmaxx();
   // int y = getmaxy();

    //setcolor(RED + BLUE);
    //line(0,y/2,x,y/2);

    //setcolor(GREEN + RED);
    //line(x/2, 0, x/2, y);

    //setcolor(GREEN + BLUE);
    //circle(x/2,y/2,100);

    initgraph(&gd, &gm, "");
    dda(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}
