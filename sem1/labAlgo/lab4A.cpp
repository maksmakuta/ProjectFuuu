#include <iostream>

using namespace std;

class Point
{
    double x, y;
public:
    Point(){}
    Point(const double X, const double Y): x(X), y(Y){}
    double X(){return x;}
    double Y(){return y;}
};

class Triangle
{
    Point vert[3];
public:
    Triangle(const Point &p1, const Point &p2, const Point &p3)
    {
        vert[0] = p1;
        vert[1] = p2;
        vert[2] = p3;
    }
    bool operator==(Point p)
    {
        double pl1, pl2, pl3;
        pl1 = (vert[0].X() - p.X())*(vert[1].Y() - vert[0].Y())-(vert[1].X() - vert[0].X())*(vert[0].Y() - p.Y());
        pl2 = (vert[1].X() - p.X())*(vert[2].Y() - vert[1].Y())-(vert[2].X() - vert[1].X())*(vert[1].Y() - p.Y());
        pl3 = (vert[2].X() - p.X())*(vert[0].Y() - vert[2].Y())-(vert[0].X() - vert[2].X())*(vert[2].Y() - p.Y());
        if ((pl1 >= 0 && pl2 >= 0 && pl3 >= 0) || (pl1 <= 0 && pl2 <= 0 && pl3 <= 0))
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{

    double a1,a2,b1,b2,c1,c2;
    cout << "Enter x and y for 3 points"<< endl;
    cout << "Point a , X: ";
    cin >> a1;
    cout << "Point a , Y: ";
    cin >> a2;
    cout << "Point b , X: ";
    cin >> b1;
    cout << "Point b , Y: ";
    cin >> b2;
    cout << "Point c , X: ";
    cin >> c1;
    cout << "Point c , Y: ";
    cin >> c2;

    Triangle t( Point(a1,a2),Point(b1,b2),Point(c1,c2));
    Point p(0,0);
    t == p ? cout <<"true": cout <<"false";
    return 0;
}
