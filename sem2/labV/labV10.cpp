#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int data[16];
    string datastr;
    cin >> datastr;
    if(datastr.size() == 16){
        for(int a = 15; a>=0; a--){
            data[a] = datastr[a] - '0';
            cout << data[a] << " ";}
        cout << endl;
        for(int a = 15; a >= 0; a--){
            if(a%2 == 1){
                data[a] *= 2;
                if(data[a] > 9){
                    int x = data[a]/10;
                    int y = data[a]%10;
                    data[a] = x + y;
                }}cout << data[a] << " ";}
        cout << endl;
        int sum = 0;
        for(int a = 15; a >= 0; a--){sum += data[a];}
        if(sum % 10 == 0){cout << "Card correct " << endl;}
        else{cout << "Card not correct " << endl;}
    }
    else{cerr << "Card have 16 digits" << endl;}
    return 0;
}
