//gcc -o app main.cpp /usr/lib/libXbgi.a -lX11 -lm
#include <graphics.h>
#define PI 3.1416926
#define LAPS 2

void rect(int x, int  y, int w,int h,int C){
    setcolor(C);
    rectangle(x,y,x+w,y+h);
}

int main (int argc, char *argv[])
{
    int gd = X11, gm = X11_1024x768;
    initgraph (&gd, &gm, (char*)"App");

    float t = 0.0f;
    while(t < LAPS*2*PI){
        int a= getmaxx()/2,b= getmaxy()/2,r = 300;
        int Cx = a + r * cos(t);
        int Cy = b + r * sin(t);
        rect(Cx, Cy, 50, 50, WHITE);
        usleep(20 * 1000);
        cleardevice();
        t += 0.01f;
    }
    int dt = 0;
    while(dt < 500){
        int a= 100,b= 100;

        rect(a+dt, b, 50, 50, RED);
        rect(a, b+dt, 50, 50, GREEN);

        usleep(16.7 * 1000);
        cleardevice();
        dt += 1;
    }

    closegraph ();
    return 0;
}