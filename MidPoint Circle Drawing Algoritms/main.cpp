#include <iostream>
#include<graphics.h>
#include<math.h>
#include<windows.h>

using namespace std;

void midPointCircle(int xc,int yc,int r){

    int x=0,y=r;
    float d = (5/4)-r;
    while(x<=y){
        if(d>=0){
            d +=2*(x-y)+5;
            x++;
            y--;
        }
        else{
            d +=2*x + 3;
            x++;
        }

        putpixel(xc+x,yc+y,GREEN);
        putpixel(xc-x,yc+y,GREEN);
        putpixel(xc+x,yc-y,GREEN);
        putpixel(xc-x,yc-y,GREEN);
        putpixel(xc+y,yc+x,GREEN);
        putpixel(xc+y,yc-x,GREEN);
        putpixel(xc-y,yc+x,GREEN);
        putpixel(xc-y,yc-x,GREEN);
        delay(100);
    }
}

int main()
{
    int gd = DETECT, gm;

    int x,y,r;
    cout<<" Enter the value of x, y and r: ";
    cin>>x>>y>>r;
    initgraph(&gd, &gm, "");

    midPointCircle(x,y,r);
    getch();
    closegraph();
    return 0;
}
