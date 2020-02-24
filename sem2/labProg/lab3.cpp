#include <iostream>
#include <string>
#include <map>

using namespace std;

/* data from websites:
    https://www.uz.gov.ua/passengers/timetable/?station=23060&by_station=1
    https://www.uz.gov.ua/passengers/timetable/?station=23160&by_station=1
*/

int mapSize = 25;
int trainCode[] = {97,98,268,58,88,128,668,127,13,601,749,133,134,8,149,43,243,1,150,144,7,130,702,606,26};
string trainStation[] = {"Kyiv - Kovel","Kovel - Kyiv","Kovel - Lviv",
                         "Kovel - Odessa","Novooleksiivka - Kovel","Kovel - Kharkiv",
                         "Kovel - Chernivtsi","Kharkiv - Kovel", "Kyiv - Solotvino",
                         "Lviv - Solotvino","Ivano-Frankivsk - Kyiv", "Ivano-Frankivsk - Mykolaiv","Ivano-Frankivsk - Rivne",
                         "Ivano-Frankivsk - Lviv", "Ivano-Frankivsk - Dnipro", "Ivano-Frankivsk - Konstantynivka",
                         "Vorohta - Poltava", "Kyiv - Chernivtsi", "Kremenchuk - Vorohta",
                         "Rahiv - Lviv","Odessa - Chernivtsi", "Odessa - Rahiv",
                         "Kharkiv - Rahiv","Chernivtsi - Kovel","Dybno - Odessa"
                        };
void initMap(map<int,string> &m){
    for(int a = 0; a < mapSize; a++)m.insert(pair<int,string>((int)trainCode[a],(string)trainStation[a]));
}

void printMap(map<int,string> &m){
    map<int,string>::iterator it;
     cout << "Num" << "\t" << "Route" << endl<<endl;
    for(it = m.begin(); it != m.end(); it++)
    {
        string num;
        if(it->first < 9 && it->first > 0){num = "00" + std::to_string(it->first);}
        else if(it->first < 99 && it->first > 10){num = "0" + std::to_string(it->first);}
        else{num = "" + std::to_string(it->first);}
        cout << num << "\t" << it->second << endl;
    }cout << endl;
}

int main()
{
    map<int,string> trainMap;
    initMap(trainMap);
    printMap(trainMap);
    int action = -1;
    while(action == -1)
    {
        cout << "###@@@###\tMain Menu\t###@@@###" << endl;
        cout << "1.Find"<<endl;
        cout << "2.Delete"<<endl;
        cout <<endl;
        cout << "0.Exit"<<endl;
        cin >> action;
        if(action == 0){return 0;}
        else
        {
            if(action == 1){
                int numberToFind;
                cout << "Enter number to find in Map\t";
                cin >> numberToFind;
                map<int,string>::iterator it;
                it = trainMap.find(numberToFind);
                if(it == trainMap.end())
                    cout << "Key-value pair not present in map" ;
                else
                    cout << "Key-value pair present : "
                         << it->first << "\t" << it->second ;
                cout << endl ;
                action = -1;
            }else if(action == 2){
                int del;
                cout << "Enter number to delete from Map\t";
                cin >> del;
                trainMap.erase(del);
                printMap(trainMap);
                 action = -1;
            }else{
                action = -1;
                cout << "Error" << endl;
            }
        }
    }
    return 0;
}
