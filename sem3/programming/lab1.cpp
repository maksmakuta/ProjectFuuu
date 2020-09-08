#include <iostream>

class Point3f;

class Point2f{

private:
    float x,y;


    float getX() const{return this->x;}
    float getY() const{return this->y;}

    void setX(float f){this->x = f;}
    void setY(float f){this->y = f;}

public:
    Point2f(){
        this->x = this->y = 0.0f;
    }

    Point2f(float a,float b){
        this->x = a;
        this->y = b;
    }

    ~Point2f(){}

    friend class Point3f;
    friend Point3f addPoint(const Point2f&,const Point3f&);
    friend void print(const Point2f&, const std::string&);
    void printPoint3f(Point3f&);
};

class Point3f{

private:
    float x,y,z;

    float getX() const{return this->x;}
    float getY() const{return this->y;}
    float getZ() const{return this->z;}

    void setX(float f){this->x = f;}
    void setY(float f){this->y = f;}
    void setZ(float f){this->z = f;}

public:
    Point3f(){
        this->x = this->y = this->z = 0.0f;
    }

    Point3f(float a,float b,float c){
        this->x = a;
        this->y = b;
        this->z = c;
    }

    friend class Point2f;
    friend Point3f addPoint(const Point2f&,const Point3f&);
    friend void    print(const Point3f&,const std::string&);
    friend void reset(Point3f, float, float, float);

    ~Point3f(){}


};

Point3f addPoint(const Point2f& a,const Point3f& b){
    float x = a.getX() + b.getX();
    float y = a.getY() + b.getY();
    float z = b.getZ();

    return Point3f(x,y,z);
}

void print(const Point2f& obj,const std::string& name) {
    std::cout << "Point " << name << "(" << obj.getX() << "," <<obj.getY() << ")" << std::endl;
}

void print(const Point3f &f,const std::string& name) {
    std::cout << "Point " << name <<"(" << f.getX() << "," <<f.getY() << "," << f.getZ() << ")" << std::endl;
}

void Point2f::printPoint3f(Point3f &obj) {
    std::cout << "Point(" << obj.x << "," <<obj.y << "," <<obj.z << ")" << std::endl;
}


void reset(Point3f p, float a, float b, float c){
    p.setX(a);p.setY(b);p.setZ(c);
}

int main() {

    Point3f p1(15.6f,15.0f,12.5f);
    print(p1,"p1");

    Point2f p2(11.9f,-23.5f);
    print(p2,"p2");

    reset(p1,10.0f,10.0f,10.0f);

    p2.printPoint3f(p1);

    Point3f tmp = addPoint(p2,p1);
    print(tmp,"tmp");

    return 0;
}
