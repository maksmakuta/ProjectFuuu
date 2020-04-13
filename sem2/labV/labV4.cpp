#include <iostream>
#include <fstream>
using namespace std;

void ReadBMP(char* filename,char* filenamenew)
{
    FILE* f = fopen(filename, "rb");
    if(f == NULL)
        throw "Argument Exception";
    unsigned char info[54];
    ofstream x(filenamenew);
    fread(info, sizeof(unsigned char), 54, f);
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    cout << endl;
    cout << "  Name: " << filename << endl;
    cout << " Width: " << width << endl;
    cout << "Height: " << height << endl;

    for(int i = 0; i < 54; i++)
    {
        x << info[i];
    }


    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];

    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width*3; j += 3)
        {
            if(data[j+2] > 250){
                data[j+0] = 250;
                data[j+1] = 250;
                data[j+2] = 250;
            }else{
                data[j+0] = 0;
                data[j+1] = 0;
                data[j+2] = 0;
            }
            x << data[j]<< data[j+1]<< data[j+2];
        }
    }
    x.close();
    fclose(f);
}

int main()
{
    ReadBMP("clue.bmp","text.bmp");
    return 0;
}
