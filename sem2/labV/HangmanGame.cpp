#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>

#define useWordFile true

// PS. Use c++11;

using namespace std;

vector<string> words;
string w;

void getWordList()
{
    if(useWordFile == true)
    {
        ifstream file("words.txt");
        string tmp;
        while (std::getline(file, tmp))
        {
            words.push_back(tmp);
        }
    }
    else
    {
        vector<string> test =
        {
            "game","stick","water","ball",
            "phone","android","vector","math",
            "notebook","pencil","table","book",
            "mouse","file","folder","movie",
            "grass","bed","circle","triangle",
            "rectangle","point","class","namespace",
            "teacher","worker","painter","space",
            "earth","moon","planet","comet",
            "steam","finger","spoon","tea"
        };
        words = test;
    }
}

string getWord()
{
    getWordList();
    int range_from  = 0;
    int range_to    = words.size();

    std::mt19937                        generator(time(0));
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    return words[distr(generator)];
}

int main()
{
    w = getWord();
    char l;
    string hidden = "";
    int lifes = 6;
    for(unsigned int a = 0; a < w.size(); a++)
    {
        hidden += "_";
    }

    while(lifes >= 0)
    {
        if(w == hidden)
        {
            std::system("cls");
            cout << "You win" << endl;
            return 0;
        }
        if(lifes == 0)
        {
            std::system("cls");
            cout << "You loose" << endl;
            return 0;
        }
        cout << "Lifes : " << lifes << endl;
        cout << "Word: " << hidden <<endl;
        cout << "Enter a letter: ";
        cin >> l;

        if ((char)w.find(l) != std::string::npos)
        {
            for(unsigned int i = 0; i < w.size(); i++)
            {
                if(w[i] == l)
                {
                    hidden[i] = w[i];
                }
            }
        }
        else
            lifes--;
        std::system("cls");
    }
    return 0;
}
