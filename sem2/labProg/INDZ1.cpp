#include <iostream>
#include <math.h>

using namespace std;

// use c++11 

class Complex // main class for complex numbers
{

private:

    float real, imag;
	// real - real number(a), imag - imaginary number (b*i)

public:
    Complex() // new clean object 
    {
        this->real = 0;
        this->imag = 0;
    }
    Complex(float r, float i) // object with data 
    {

        this->real = r;
        this->imag = i;

    }
    Complex(Complex &c) // object based on other object
    {
        this->real = c.getReal();
        this->imag = c.getImag();
    }
    //////////////get methods //////////////////
    float getReal() // return real to user 
    {
        return real;
    }
    float getImag() // return imag to user 
    {
        return imag;
    }
    ///////////////// set methods //////////////
    void setImag(float i) // set imag from user 
    {
        this->imag = i;
    }
    void setReal(float r) // set real from user 
    {
        this->real = r;
    }

    float calc() // module of Complex number
    {
        return sqrt(imag * imag + real * real);
    }

    friend Complex& operator+(Complex &x, Complex &y) // operator +
    {
        Complex *z = new Complex();
        float a = x.getReal(),b = x.getImag(),c = y.getReal(),d = y.getImag();
        float real = a + c;
        float imag = b + d;
        z->setReal(real);
        z->setImag(imag);
        return *z;
    }

    friend Complex& operator - (Complex &x, Complex &y) // operator -
    {
        Complex *z = new Complex();
        float a = x.getReal(),b = x.getImag(),c = y.getReal(),d = y.getImag();
        float real = a - c;
        float imag = b - d;
        z->setReal(real);
        z->setImag(imag);
        return *z;
    }
    friend Complex& operator * (Complex &x, Complex &y) // operator *
    {
        Complex *z = new Complex();
        float a = x.getReal(),b = x.getImag(),c = y.getReal(),d = y.getImag();
        float real = a*c - b*d ;
        float imag = a*d + b*c;
        z->setReal(real);
        z->setImag(imag);
        return *z;
    }
    Complex& operator * (float const b) // operator * (complex * number )
    {
        real = getReal() * b;
        imag = getImag() * b;
        return *this;
    }
    friend Complex& operator / (Complex &x, Complex &y) // operator /
    {
        Complex *z = new Complex();
        float a = x.getReal(),b = x.getImag(),c = y.getReal(),d = y.getImag();
        float real = (a*c + b*d)/(c*c + d*d);
        float imag = (b*c - a*d)/(c*c + d*d);
        z->setReal(real);
        z->setImag(imag);
        return *z;
    }
    Complex& operator = (Complex &a) // operator equal
    {
        real = a.getReal();
        imag = a.getImag();
        return *this;
    }
    friend bool operator == (Complex &a, Complex &b) // bool operator ==
    {
        return a.calc() == b.calc()? true : false;
    }
    friend bool operator > (Complex &a, Complex &b)// bool operator >
    {
        return a.calc() > b.calc()? true : false;
    }
    friend bool operator < (Complex &a, Complex &b)// bool operator <
    {
        return a.calc() < b.calc()? true : false;
    }
    friend ostream& operator <<(ostream &a, Complex &b) // operator for printing Complex number 
    {
        if(b.getImag() < 0)
            a << b.getReal() << "" << b.getImag()<<"i";
        else
            a << b.getReal() << "+" << b.getImag()<<"i";
        return a;
    }
    ~Complex() {} // destroy class object
};

int main()
{
	
	
	Complex a(1,5); // init complex num a
	Complex b(3,8); // init complex num b


    cout << a << " +  " << b << " -> " << a + b << endl;
    cout << a << " -  " << b << " -> " << a - b << endl;
    cout << a << " *  " << b << " -> " << a * b << endl;
    cout << a << " /  " << b << " -> " << a / b << endl;
		// comparing complex numbers
    bool x = a > b;
    bool z = a < b;
    bool y = a == b;
    cout << a << " >  " << b << " -> " << x << endl;
    cout << a << " <  " << b << " -> " << z << endl;
    cout << a << " == " << b << " -> " << y << endl;
    return 0;
}
