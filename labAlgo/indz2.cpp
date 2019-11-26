#include <iostream>
#include <string>
#include <algorithm>
# define NO_OF_CHARS 256

using namespace std;

int primitive(string s, string c, int n)
{
    int i, j;
    int lenC = c.size(), lenS = s.size();
    for (i = 0; i <= lenS - lenC; i++)
    {
        for (j = 0; s[i + j] == c[j]; j++);
        if (j - lenC == 1 && i == lenS - lenC && !(n - 1))
            return i;
        if (j == lenC)
            if (n - 1)
                n--;
            else
                return i;
    }
    return -1;
}

int knuthmorrispratt(string str, string pattern)   // Knuth–Morris–Pratt algorithm
{

    // Step 0. Should not be empty string
    if( str.size() == 0 || pattern.size() == 0)
        return -1;

    // Step 1. Compute failure function
    int failure[pattern.size()];
    std::fill( failure, failure+pattern.size(), -1);

    for(int r=1, l=-1; r<pattern.size(); r++)
    {

        while( l != -1 && pattern[l+1] != pattern[r])
            l = failure[l];

        // assert( l == -1 || pattern[l+1] == pattern[r]);
        if( pattern[l+1] == pattern[r])
            failure[r] = ++l;
    }

    // Step 2. Search pattern
    int tail = -1;
    for(int i=0; i<str.size(); i++)
    {

        while( tail != -1 && str[i] != pattern[tail+1])
            tail = failure[tail];

        if( str[i] == pattern[tail+1])
            tail++;

        if( tail == pattern.size()-1)
            return i - tail;
    }

    return -1;
}
int p(string s, string c)
{
    int i, n = 0;

    for (i = 1; n != -1; i++)
    {
        n = primitive(s, c, i);

        if (n >= 0)
            return n;
        else
            return -1;
    }
    return -1;
}

void badCharHeuristic( string str, int size,
                        int badchar[NO_OF_CHARS])
{
    int i;
      for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
  for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void boyer_moore( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;

        while(j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            cout << "pattern occurs at shift = " <<  s << endl;

            s += (s + m < n)? m-badchar[txt[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main()
{
    string s,c;
    cout << "enter text ";
    cin >> s;
    cout << "enter text for find ";
    cin >> c;

cout << endl;

        cout << "simple algorithm" << endl;
        cout << p(s,c)<< endl;

cout << endl;

        cout << "boyer moore algorithm" << endl;
                boyer_moore(s, c);
cout << endl;

        cout << "Knuth Morris Pratt algorithm " <<endl;
        cout << knuthmorrispratt(s,c) << endl;

cout << endl;
}
