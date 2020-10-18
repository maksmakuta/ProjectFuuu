//gcc -o app main.cpp /usr/lib/libXbgi.a -lX11 -lm
#include <graphics.h>

using namespace std;

class Rect{
private:
    int dir;
    int x,y;
    int sizeX,sizeY;
    int color;

    void rect(int dx, int dy){
        setcolor(color);
        this->x += dx;
        this->y += dy;
        rectangle(x,y,x+sizeX,y+sizeY);
    }
public:

    Rect(){
        this->x = 0;
        this->y = 0;
        this->sizeX = 0;
        this->sizeY = 0;
        this->dir = 0;
        this->color = 0;
    }

    Rect(int xpos, int ypos,int sX, int xY, int d,int C){
        this->x = xpos;
        this->y = ypos;
        this->sizeX = sX;
        this->sizeY = xY;
        this->dir = d;
        this->color = C;
    }
    int getX(){return this->x;}
    int getY(){return this->y;}

    void setDir(int d){this->dir = d;}

    void changeSize(int a, int b){
        this->sizeX = a;
        this->sizeY = b;
    }

    void setX(int newX){this->x = newX;}
    void setY(int newY){this->y = newY;}

    void move(int dt){
        switch (dir) {
            case 1 :  rect(dt,0); break;
            case 2 :  rect(0,dt); break;
            case 3 :  rect(-dt,0); break;
            case 4 :  rect(0,-dt); break;

            case 5 :  rect(dt,dt); break;
            case 6 :  rect(-dt,-dt); break;
            case 7 :  rect(-dt,dt); break;
            case 8 :  rect(dt,-dt); break;
        }
    }
};

int main ()
{

    const int s = 200;
    Rect rect[s];
    for(int a = 0; a < s; a++){
        rect[a] = Rect(rand()%800,rand()%600,rand()%80,rand()%80,rand()%8+1,rand()%16);
    }

    int gd = X11, gm = X11_800x600;
    initgraph (&gd, &gm, (char*)"App");

    while(true) {
        for (int a = 0; a < s; a++) {
            rect[a].move(rand()%5);

            if (rect[a].getX() > 800 || rect[a].getX() < 0) {
                rect[a].setX(rand() % 600);
                rect[a].setDir(rand() % 8 + 1);
                rect[a].changeSize(rand() %200,rand() %120);
            }
            if (rect[a].getY() > 600 || rect[a].getY() < 0) {
                rect[a].setY(rand() % 800);
                rect[a].setDir(rand() % 8 + 1);
                rect[a].changeSize(rand() %200,rand() %120);
            }
        }
        cleardevice();
        usleep(20 * 1000);
    }

    closegraph ();
    return 0;
}