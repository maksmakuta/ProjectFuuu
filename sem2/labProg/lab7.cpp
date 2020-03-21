#include <iostream>

using namespace std;

class Binom
{
private:
    int a,b,result;
    char op;
public:
    Binom()
    {
        this->a = 0;
        this->b = 0;
        this->op = '+';
    }
    Binom(int x, char binomOperator, int y)
    {
        this->a = x;
        this->b = y;
        this->op = binomOperator;
    }

    ///////////////////get methods //////////////////
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    char getOperator()
    {
        return op;
    }

    /////////////////// set methods //////////////////

    void setA(int newA)
    {
        this->a = newA;
    }
    void setB(int newB)
    {
        this->b = newB;
    }
    void setOperator(char newOp)
    {
        this->op = newOp;
    }

    void print()
    {
        cout << a << op << b << endl;
    }

    int calc()
    {
        switch(op)
        {
        case'+':
            result = a + b;
            break;
        case'-':
            result = a - b;
            break;
        default:
            cerr << "Unknown Operator for Binom" << endl;
            result = INT_MIN;
        }
        return result;

    }

    friend bool operator !=(Binom &a, Binom &b)
    {
        if(a.calc() != b.calc())
            return true;
        else
            return false;
    }
    friend bool operator ==(Binom &a, Binom &b)
    {
        if(a.calc() == b.calc())
            return true;
        else
            return false;
    }

    friend bool operator >=(Binom &a, Binom &b)
    {
        if(a.calc() >= b.calc())
            return true;
        else
            return false;
    }
    friend bool operator <=(Binom &a, Binom &b)
    {
        if(a.calc() <= b.calc())
            return true;
        else
            return false;
    }
    friend bool operator <(Binom &a, Binom &b)
    {
        if(a.calc() < b.calc())
            return true;
        else
            return false;
    }
    friend bool operator >(Binom &a, Binom &b)
    {
        if(a.calc() > b.calc())
            return true;
        else
            return false;
    }

    friend ostream& operator << (ostream &o,Binom &a)
    {
        if(a.getA() < 0)
            o <<"("<< a.getA()<<")" << a.getOperator() << a.getB();
        else if(a.getB() < 0)
            o << a.getA() << a.getOperator()<< "(" << a.getB() << ")" ;
        else if ( a.getA() < 0 && a.getB() < 0)
             o <<"("<< a.getA()<<")" << a.getOperator()<< "(" << a.getB() << ")" ;
        else
             o << a.getA() << a.getOperator() << a.getB();
    }

    friend istream& operator >> (istream &i,Binom &x)
    {
        cout << "Enter a: ";
        int xA;
        i >> xA;
        x.setA(xA);
        cout << "Enter operator (only + and - ): ";
        char xO;
        i >> xO;
        x.setOperator(xO);
        cout << "Enter b: ";
        int xB;
        i >> xB;
        x.setB(xB);
    }

    ~Binom() {}

};

int main()
{
    Binom binomA(1,'+',2);
    Binom binomB(0,'-',0);

    cin >> binomB;

    bool a = binomA != binomB;
    bool b = binomA == binomB;
    bool c = binomA <= binomB;
    bool d = binomA >= binomB;
    bool e = binomA  < binomB;
    bool f = binomA  > binomB;

    cout << binomA << " = " << binomA.calc() << endl;
    cout << binomB << " = " << binomB.calc() << endl;

    cout << binomA << " != " << binomB << " -> " << a << endl;
    cout << binomA << " == " << binomB << " -> " << b << endl;
    cout << binomA << " >= " << binomB << " -> " << d << endl;
    cout << binomA << " <= " << binomB << " -> " << c << endl;
    cout << binomA << " < " << binomB << " -> " << e << endl;
    cout << binomA << " > " << binomB << " -> " << f << endl;
    return 0;
}
