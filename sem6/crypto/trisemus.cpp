#include "c++.h"

#define S 6
#define for_i(t,a,b) for(int t = a;t < b;t++)

string min(const string& text){
    string data;
    for_i(i,0,text.size()){
        int a = 0,t = data.size();
        while(t --> 0) if(data[t] == text[i]) ++a;
        if(a == 0)
            data += text[i];
    }
    return data;
}

void makeTable(char* table, const string key){
    for_i(i,0,S*S){
        table[i] = 'a' + i;
    }
    for_i(i,0,key.size()){
        int p = 0;
        for_i(j,0,S*S){
            if(key[i] == table[j])
                p = j;
        }
        if(i != p)
            std::swap(table[p],table[i]);
    }

    cout << "Table : \n";
    for_i(i,1,S*S+1){
        cout << (char)table[i-1] << " ";
        if( i % S == 0) cout << '\n';
    }
    cout << '\n';
}

string encode(char* table,const string data){
    string enc;
    for(char c : data)
        for_i(i,0,S*S)
            if(table[i] == c)
                enc += table[i+S];
    return enc;
}

int main(int argc,char** argv){
    if(argc < 3){
        cout << "Usage : " << argv[0] << " key data\n";
    }else{
        string key = argv[1];
        string data = argv[2];
        key = min(key);
        cout << "key : " <<  key << endl;
        auto table = new char[S*S];
        makeTable(table,key);
        cout << "encoded : " << encode(table,data) << endl;
        delete []table;
    }
    return 0;
}

