//gcc -o app main.cpp /usr/lib/libXbgi.a -lX11 -lm
#include <graphics.h>

#define size 50

void rect(int x,int y, int s) {
    rectangle(x,y,x+s,y+s);
    bar(x,y,x+s,y+s);
}

int main (){
    int gd = X11, gm = X11_800x600;
    initgraph (&gd, &gm, (char*)"xxx");
    settextstyle(DEFAULT_FONT,0,16);
    for(int a = 1; a <= 8;a++) {

        int x = 'A' - 1 + a;
        char* d; d[0]= x;
        outtextxy((size * a) +(size/2), size-20, d);

        for (int b = 1; b <= 8; b++) {
            if ((a+b)%2 == 0)
                rect(size*a+1, size*b+1, size);
        }

        d[0] -= 16;
        outtextxy(size-20,(size * a) +(size/2), d);
        //getch();
    }

    getch();
    closegraph ();
    return 0;
}