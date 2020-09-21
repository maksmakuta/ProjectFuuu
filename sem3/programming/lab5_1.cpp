/*
 * To compile:
 * gcc -o fonts font.cpp -lSDL_bgi -lSDL2
 *
 *
 */

#include <string.h>
#include <graphics.h>

char data[]  = "Maks Makuta";

int type[10] = {
        DEFAULT_FONT,
        TRIPLEX_FONT,
        SMALL_FONT,
        SANS_SERIF_FONT,
        GOTHIC_FONT,
        SCRIPT_FONT,
        SIMPLEX_FONT,
        TRIPLEX_SCR_FONT,
        COMPLEX_FONT,
        LAST_SPEC_FONT
};
int colors[15] = {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
        DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
        LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE,
};

void message (int x, int y,int col, int font, char str[])
{
    settextstyle (font, HORIZ_DIR, 0);
    setcolor (col);
    outtextxy (x, y, str);
}


int main (int argc, char *argv[])
{

    int gd = DETECT, gm;

    initgraph (&gd, &gm, data);
    setbkcolor (WHITE);
    cleardevice();

    for(int z = 0; z < 10;z+=2){
        cleardevice();
        for(int b = 0; b < 10;b++){
            message(10,b*50,colors[b],type[z],data);
            message(300,b*50,colors[b],type[z+1],data);
        }
        getch ();
    }

    message(getmaxx()/4,getmaxy()-100,BLACK,SANS_SERIF_FONT,(char*)"Type any key to exit...");
    getch();
    closegraph ();

}
