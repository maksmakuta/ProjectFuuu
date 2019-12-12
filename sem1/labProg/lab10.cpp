#include <iostream>

using namespace std;

int main()
{
    const int sizeC = 100;
    char text[sizeC];
    cin.getline(text,sizeC);

    //if(text.size() > 0){
            for(int a = 0; a <= sizeC; a++){
                     if(text[a] == 'r')
                    text[a] = 'k';
                else if(text[a] == 's')
                    text[a] = 'l';
                else if(text[a] == 't')
                    text[a] = 'm';
                else if(text[a] == 'R')
                    text[a] = 'K';
                else if(text[a] == 'S')
                    text[a] = 'L';
                else if(text[a] == 'T')
                    text[a] = 'M';
            }
    //}
    cout << text << endl;
    return 0;
}
