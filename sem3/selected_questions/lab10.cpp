#include "TextParser.h"

#define FILE1 "../refr.txt"
#define FILE2 "../logs.txt"
#define FILE3 "../mags.txt"

void t3(){
    TextParser t(FILE1);
    t.readData();

    for(int a = 1; a <= t.getLines();a++){
        vector<string> tokens = t.tokenizeLine(a);
        string priceStr = tokens[1];
        int p = t.parseInt(priceStr);
        if(p > 55000){
            t.print(tokens);
        }
    }

}

void printAll(TextParser& tp){
    for(int a = 1;a <= tp.getLines();a++){
        cout << tp.readLine(a) << endl;
    }
}

void printBetter23(TextParser& tp){
    vector<string> tokens = tp.tokenizeLine(1);

    int *lessonsB = new int[5];
    lessonsB[0] = tp.parseInt(tokens[1]);
    lessonsB[1] = tp.parseInt(tokens[2]);
    lessonsB[2] = tp.parseInt(tokens[3]);
    lessonsB[3] = tp.parseInt(tokens[4]);
    lessonsB[4] = tp.parseInt(tokens[5]);
    for(int a = 2;a <= tp.getLines();a++){
        vector<string> tokens1 = tp.tokenizeLine(a);
        int *lessons = new int[5];
        lessons[0] = tp.parseInt(tokens1[1]);
        lessons[1] = tp.parseInt(tokens1[2]);
        lessons[2] = tp.parseInt(tokens1[3]);
        lessons[3] = tp.parseInt(tokens1[4]);
        lessons[4] = tp.parseInt(tokens1[5]);

        if(lessons[0] == lessonsB[0] && lessons[1] == lessonsB[1] &&
                lessons[2] == lessonsB[2] && lessons[3] == lessonsB[3] &&
                lessons[4] == lessonsB[4] ){
            tp.print(tokens1);
        }
    }
}

void add(TextParser & tp){
    cout << "Example -> " << tp.readLine(2) << endl;
    string data;
    cin.ignore();
    getline(cin,data);
    data += "\n";
    tp.write(data);
}


void remove(TextParser & tp){
    int a ;
    cout << "Enter line to remove -> "; cin >> a;
    tp.deleteLine(a);
}

void t23(){
    TextParser t(FILE2);
    t.readData();
    int action;
    printf("Menu:\n\n");
    printf("0. PrintAll\n");
    printf("1. PrintBetter\n");
    printf("2. Add\n");
    printf("3. Remove\n");
    printf("4. Exit\n\n");
    std::cin >> action;
    switch (action) {
        case 0:printAll(t);t23();break;
        case 1:printBetter23(t);t23();break;
        case 2:add(t);t23();break;
        case 3:remove(t);t23();break;
        case 4: break;
        default: t23();break;
    }
}


void printBetter12(TextParser& tp){
    for(int a = 2;a <= tp.getLines();a++){
        vector<string> tokens1 = tp.tokenizeLine(a);
        int mClass = tp.parseInt(tokens1[2]);
        if(mClass == 1){
            tp.print(tokens1);
        }
    }
}

void t12(){
    TextParser t(FILE3);
    t.readData();
    int action;
    printf("Menu:\n\n");
    printf("0. PrintAll\n");
    printf("1. PrintBetter\n");
    printf("2. Add\n");
    printf("3. Remove\n");
    printf("4. Exit\n\n");
    std::cin >> action;
    switch (action) {
        case 0:printAll(t);t12();break;
        case 1:printBetter12(t);t12();break;
        case 2:add(t);t12();break;
        case 3:remove(t);t12();break;
        case 4: break;
        default: t12();break;
    }
}

int main() {
    t12();
    return 0;
}
