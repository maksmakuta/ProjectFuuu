#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>


int getWords(std::string file)
{
    std::ifstream infile(file);
    std::istream_iterator<std::string> in{ infile }, end;
    int w = std::distance(in, end);
    return w;
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

class Lexer
{

    std::string n;
    int x;
    std::vector<std::string> vars;
    std::vector<std::string> code;

public:

    Lexer(std::string fileName, int words)
    {
        this->n = fileName;
        this->x = words;

        std::cout << std::setw(60)<< "###############################################################"<<std::endl;
        std::cout << std::setw(20)<< "Lexer Type #" << "\t    \t" << "# Object" <<std::endl;
        std::cout << std::setw(60)<< "###############################################################"<<std::endl;

        std::ifstream file(n);
        char data[10];
        bool boolData[15];

        code.push_back("0");
        while(file>>data )
        {
            code.push_back(data);
        }

        for(int a = 1; a<= words; a++)
        {
            std::string d = code[a];
            std::string nd = code[a+1];
            std::string pd = code[a-1];

            boolData[0] = isDef(d);
            boolData[1] = isFunc(d);
            boolData[2] = isCreep(d);
            boolData[3] = isPrintFunc(d);
            boolData[4] = isReturn(d);
            boolData[5] = isNum(d);
            boolData[6] = isDOT(d);
            boolData[7] = isOP(d);
            boolData[8] = isString(d);
            boolData[9] = isFNumber(d);
            boolData[10] = isDNumber(d);
            boolData[11] = isID(d,pd);
            boolData[12] = isMainFunc(d);

            printLexs(boolData,d);

            if(d[0] >= 'a' && d[0] <= 'z' && isID(d,pd) == true && (!boolData[0] && !boolData[1] && !boolData[2] &&
                    !boolData[3] && !boolData[4] && !boolData[5] &&
                    !boolData[6] && !boolData[7] && !boolData[8] &&
                    !boolData[9] && !boolData[10] && boolData[11] && !boolData[12] ))
            {
                if(isDeclared(d) == false)
                {
                    vars.push_back(d);
                }
            }
        }
        std::ifstream file1(n);
        std::string data1;
        std::cout << "Code :" <<std::endl;
        while (file1 >> data1)
        {
            SetColor(15);
            if(data1[0] == '{' || data1[0] == ';')
            {
                std::cout << data1 << std::endl;
            }
            else if(data1 == "print" || data1 == "return")
            {
                std::cout << "" << data1 << " ";
            }
            else
            {
                if( data1[0] >= 'a' && data1[0] <= 'z' && isDeclared(&data1[0]) == false && data1.size() == 1)
                {
                   SetColor(4);
                    std::cout << data1 << " ";
                }
                else
                {
                   SetColor(15);
                    std::cout << data1 << " ";

                }

            }

        }
        std::cout << "\n";

        for(unsigned int a = 0; a <= vars.size(); a++)
        {
            std::cout << vars[a] << " ";
        }
    };



    void printLexs(bool boolData[10], std::string text)
    {
        std::string desc;

        if(boolData[0] == true)
            desc = "Type";
        else if(boolData[1] == true)
            desc = "Function";
        else if(boolData[2] == true)
            desc = "Creep";
        else if(boolData[3] == true)
            desc = "Print Function";
        else if(boolData[4] == true)
            desc = "Return";
        else if(boolData[5] == true)
            desc = "Number";
        else if(boolData[6] == true)
            desc = "DOT.Comma";
        else if(boolData[7] == true)
            desc = "Math Operator";
        else if(boolData[8] == true)
            desc = "String text";
        else if(boolData[9] == true)
            desc = "Number Float";
        else if(boolData[10] == true)
            desc = "Number Double";
        else if(boolData[11] == true)
            desc = "ID ";
        else if(boolData[12] == true)
            desc = "Main Function";
        else
            desc = "UNKNOWN";


        std::cout << std::setw(20)<< desc << "\t -> \t" << text <<std::endl;

    }

private:

    bool isDef(std::string a)
    {
        return a == "int" || a == "float"
               ||a == "double" || a == "char" || a == "string" || a == "bool";
    }

    bool isFunc(std::string f)
    {
        return isDef(f) || f == "void";
    }
    bool isMainFunc(std::string m)
    {
        return m == "main()";
    }
    bool isCreep(std::string c)
    {
        return c == "{" || c == "}" || c == "(" || c == ")" || c == "((" || c == "))";
    }
    bool isPrintFunc(std::string p)
    {
        return p == "print";
    }
    bool isReturn(std::string p)
    {
        return p == "return";
    }
    bool isNum(std::string p)
    {
        return p == "0" || p == "1" || p == "2" ||p == "3" ||p == "4" ||p == "5" ||p == "6" ||p == "7" ||p == "8" ||p == "9";
    }
    bool isDOT(std::string d)
    {
        return d==";";
    }
    bool isOP(std::string o)
    {
        return o == "+" || o == "-" || o == "=";
    }

    bool isString(std::string o)
    {
        return o.find('"') != std::string::npos;
    }

    bool isFNumber(std::string o)
    {
        return o.find('f') != std::string::npos && o.find('.') != std::string::npos;
    }
    bool isDNumber(std::string o)
    {
        return o.find('.') != std::string::npos;
    }

    bool isID(std::string o, std::string prev)
    {
        if(o == "main()" && prev == "int")
            return false;

        bool id = (o[0] >= 'a' && o[0] <= 'z' && isDef(prev)) || (o[0] == '_' && isDef(prev) );
        return id + isDeclared(o);
    }

    bool isDeclared(std::string o)
    {
        return std::find(vars.begin(), vars.end(), o) != vars.end();
    }

    bool isDeclared(char c[])
    {
        std::string o(c);
        return std::find(vars.begin(), vars.end(), o) != vars.end();
    }

};


int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string fileName = "main.txt";

    Lexer i(fileName, getWords(fileName));

    return 0;
}
