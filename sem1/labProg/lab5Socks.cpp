#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x= 0;
    int s[7] = {1, 2, 1, 2, 1, 3, 2};
    int n = sizeof(s) / sizeof(s[0]);
    sort(s, s + n);
    for(int a = 0; a <= n; a++) if(s[a] == s[a + 2]) x++;
     cout << x << endl;
    return 0;
}
