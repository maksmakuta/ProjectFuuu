#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <graphics.h>

#define D pow(2,6)
#define f(x) x*x*x // main fun
#define F(x) (f(x))/D

using namespace std;

void p(int x, int y,char* data){
    setcolor(WHITE);
    settextstyle (SANS_SERIF_FONT, HORIZ_DIR, 0);
    outtextxy(x,y,data);
}

class P{
private:
    int x,y;
public:
    P(){
        this->x = 0;
        this->y = 0;
    }
    P(int a, int b){
        this->x = a;
        this->y = b;
    }
    int getX(){return x;}
    int getY(){return y;}
};
class T{
private:
    int sX, sY;
    int tColor = WHITE, fColor = RED;
    vector<P> f;
public:
    T(int x,int y){
        this->sX = x;
        this->sY = y;
    }

    void setTColor(int c){this->tColor = c;}
    void setFColor(int c){this->fColor = c;}

    void draw(){
        int mX = sX / 2;
        int mY = sY / 2;
        int f = 10;
        setcolor(tColor);
        line(mX, 0,mX,sY);
        line(0 ,mY,sX,mY);
        line(mX-f,f,mX,0);
        line(mX+f,f,mX,0);
        line(sX-f,mY-f,sX,mY);
        line(sX-f,mY+f,sX,mY);
        p(mX - 2*f,        f, (char*)"Y");
        p(sX- f,    mY + 2*f, (char*)"X");
        formula();
    }
    void formula() {
        for (float x = (-1) * (sX / 2); x < (sX / 2); x += 0.01f) {
            int fx = (sX / 2) - x;
            int fy = (sY / 2) - F(x);
            if (fy >= 0 && fy <= sY) {
                f.push_back(P(fx, fy));
            }
        }
    }
    void fDrawP(){
        for(u_int a = 1; a < f.size(); a++){
            putpixel(f[a-1].getX(),f[a-1].getY(),fColor);
        }
    }

    void fDrawL(){
        for(u_int a = 1; a < f.size(); a++){
            setcolor(fColor);
            line(f[a-1].getX(),f[a-1].getY(),f[a].getX(),f[a].getY());
        }
    }
};

int main ()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, (char*)"main ");
    cleardevice ();
    T t(400,400);
    t.draw();
    t.fDrawP();
    p(500,120,(char*)"Maks Makuta");
    p(520,150,(char*)"y = x*x*x"    );
    getch();
    closegraph();

}
