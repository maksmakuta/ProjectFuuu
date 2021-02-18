#include <QtCore>

class Point{
private:    int x; int y;
public:
Point(){this->x = 0;this->y = 0;}
Point(int a, int b){this->x = a;this->y = b;}
Point(const Point& obj){this->x = obj.getX();this->y = obj.getY();}
void operator = (Point p){setX(p.getX());setY(p.getY());}
void setX(int nX){this->x = nX;}
int getX(){return x;}
int getX() const{return x;}
void setY(int nY){this->y = nY;}
int getY(){return y;}
int getY() const{return y;}};

Point a,b,c,d;

/*      b       c
 *      *-------*
 *      |       \
 *      |       \
 *      *-------*
 *      a       d
 *
 */

Point load(){
    Point p;
    QTextStream cin(stdin);
    int x(0),y(0);
    cin >> x >> y;
    p.setX(x); p.setY(y);
    return p;
}

bool check(Point a,Point b,Point c){
    bool q = true;
    if(a.getX() != b.getX()){
        q = false;
    }
    if(b.getY() != c.getY()){
        q = false;
    }
    if(c.getX() - a.getX() != c.getX() - b.getX()){
        q = false;
    }
    return q;
}

int main(){
    a = load();
    b = load();
    c = load();

    if(check(a,b,c)){
        d.setX(c.getX());
        d.setY(a.getY());

        QTextStream(stdout) << d.getX() << " " << d.getY() << "\n";
    }else{
        QTextStream(stdout) << "Error!!!\n";
    }
}
