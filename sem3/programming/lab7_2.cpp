//gcc -o app main.cpp /usr/lib/libXbgi.a -lX11 -lm
#include <graphics.h>

#define PI 3.1415926
int a = -200, b = 600-30, r = 30;

void wheel(int dx, float f){
    int  x = a+dx + r * cos(f);
    int x1 = a+dx + r * cos(f + (4*PI)/3);
    int x2 = a+dx + r * cos(f + (2*PI)/3);

    int  y = b + r * sin(f);
    int y1 = b + r * sin(f + (4*PI)/3);
    int y2 = b + r * sin(f + (2*PI)/3);

    for(float f = PI; f < 2*PI;f += 0.01f) {
        int x = a + dx + (r+10) * cos(f);
        int y = b + (r+10) * sin(f);
        putpixel(x,y,WHITE);
    }

    circle(a+dx, b, r);
    line(a+dx,b,x,y);
    line(a+dx,b,x1,y1);
    line(a+dx,b,x2,y2);
}

void body(int dx){
    line(a+dx+100,b-80,a+dx+120,b-50);
    line(a+dx+120,b-50,a+dx+220,b-45);
    line(a+dx+220,b-45,a+dx+225,b-35);
    line(a+dx-r-10,b,a+dx-r-10,b-30);
    line(a+dx-r-10,b-30,a+dx+100,b-80);
    line(a+dx+r+10,b,a+dx+190-r,b);
    line(a+dx+110,b-50,a+dx+50,b-50);
    line(a+dx+100,b-70,a+dx+50,b-50);
    line(a+dx+100,b-70,a+dx+110,b-50);
}

int main (){
    int gd = X11, gm = X11_800x600;
    initgraph (&gd, &gm, (char*)"xxx");


    setcolor(WHITE);
    int dx = 0;
    float f = 0;
    while(dx < 5000){
        wheel(dx,f);
        body(dx);
        wheel(dx+200,f);
        cleardevice();
        usleep(25*1000);
        dx+=10;
        f+=0.15f;
    }
    getch();
    closegraph ();
    return 0;
}