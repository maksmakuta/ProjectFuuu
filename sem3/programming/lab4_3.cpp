#include <graphics.h>

int gdriver = VGA, gmode, errorcode;

void init(){
    initgraph(&gdriver, &gmode,(char*)("C://BGI//BGI"));
    errorcode = graphresult();

    if (errorcode !=grOk){
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        getch();
        exit(1);
    }
}
void deit(){
    getch();
    closegraph();
}


class Point{
private:
    int x,y;
public:
    Point(){
        this->x = 0;
        this->y = 0;
    }

    Point(int a, int b){
        this->x = a;
        this->y = b;
    }

    int getX(){return x;}
    int getY(){return y;}

};

void drawH(){
    int cX = 200,cY = 200,r = 88;
    Point data[7];
    int i = 0;
    for(float a = 0; a <= 3.14f*2.0f; a+=3.14f/3.0f){
        int x = cX + r * sin(a);int y = cY + r * cos(a);
        data[i] = Point(x, y);
        i++;
    }
    for(int a = 0; a < 6; a++ ) {
        line(data[a].getX(), data[a].getY(), data[a + 1].getX(), data[a + 1].getY());
        if (a % 2 == 1) {
            line(data[a].getX(), data[a].getY(), 200, 200);
        }
    }
    line(data[5].getX()+20,data[5].getY(),200,210);
    line(data[6].getX(),data[6].getY()-10,data[5].getX()+20,data[5].getY());
    line(data[6].getX(),data[6].getY()-10,data[1].getX()-20,data[1].getY());
    line(200,210,data[1].getX()-20,data[1].getY());


    line(data[3].getX()+5,data[3].getY()+10,data[2].getX()-50,data[2].getY()+10);
    line(210,190,data[2].getX()-50,data[2].getY()+10);

    line(data[3].getX()+5,data[3].getY()+10,data[2].getX()-7,data[2].getY()+3);
    line(data[1].getX()-5,data[1].getY()-15,210,190);
}


int main (){
    init();

    circle(200,200,100);
    drawH();
    deit();
    return 0;
}