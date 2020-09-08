#include <iostream>
#include <string>

using namespace std;

int main(){
    int count = 0;
    for(int a = 1000; a < 10000; a++){
        string num = to_string(a);
        if(num[0] == num[3] && num[1] == num[2]){
            cout << num << endl;
            count++;
        }
    }
    cout << "All numbers : " << count << endl;

    return 0;
}
