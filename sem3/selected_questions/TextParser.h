#ifndef FILELAB_TEXTPARSER_H
#define FILELAB_TEXTPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename A> void printArray(vector<A> data){
    for(A &item : data){
        cout << item << " ";
    }
    cout << endl;
}

class TextParser{
public:

    TextParser(string n){
        this->name = std::move(n);
    }

    void readData() {
        spaces.clear();
        lineLenght.clear();
        i.open(name);
        allData.assign((std::istreambuf_iterator<char>(i)), std::istreambuf_iterator<char>());
        int lines = 0, lineChars = 0;
        for (int a = 1; a <= allData.size() - 1; a++) {
            lineChars++;
            if (allData[a] == ' ' && allData[a - 1] != ' ') spaces.push_back(a);
            if (allData[a] == '\n') {
                lines++;
                lineLenght.push_back(lineChars);
                lineChars = -1;
            }
        }
        fileLines = lines;
        i.close();
    }

    string readLine(int line){
        i.open(name);
        int curr_line = 0;
        string dataLine;
        while (curr_line != line && getline(i, dataLine)) {
            ++curr_line;
        }
        i.close();
        return dataLine;
    }

    void write(string &data){
        o.open(name);
        o.clear();
        o << allData;
        o << data;
        o.close();
    }

    void deleteLine(int line){
        o.open(name);
        o.clear();

        stringstream ss;
        int s = 0;
        for(int a = 0; a < line;a++){
            s += lineLenght[a];
        }
        ss << allData.substr(0,s);
        int p = lineLenght[line] +1 ;
        ss << allData.substr(s+p,allData.size());
        o << ss.str();
        o.close();
    }

    vector<string> tokenizeLine(int line){
       string lineStr = readLine(line);
        vector<string> tokens;
        stringstream checker(lineStr);
        string tmp;
        while(getline(checker, tmp, ' '))
            tokens.push_back(tmp);
        return tokens;
    }

    void print(vector<string> tokens){
        for(string& str : tokens){
            cout << str << " ";
        }
        cout << endl;
    }

    int parseInt(string &num){
        int number = 0;
        for(int a = 0;a < num.length();a++){
            int charInt = char_to_int(num[a]);
            number += charInt * dec_pow(num.length() - a -1);
        }
        return number;
    }

    vector<int> getSpacesPos(){return spaces;}
    vector<int> getLineLength(){return lineLenght;}
    int getLines()            {return fileLines;}

private:
    string name,allData;
    vector<int> spaces,lineLenght;
    int fileLines;
    ifstream i;
    ofstream o;

    int char_to_int(char c){
        switch (c) {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            default: return -1;
        }
    }

    int dec_pow(int p){
        int n = 1,q = 0;
        while (q < p){
            q++;
            n *= 10;
        }
        return n;
    }
};

#endif //FILELAB_TEXTPARSER_H
