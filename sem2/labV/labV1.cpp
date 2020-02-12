#include <iostream>
#include <math.h>
#include <string>

using namespace std;

///////global ////////
double arrayList[] = {189.2, 1006.5, 10.8, 120.1, 1010.16, 705, 15.1};  // for Min()
string number = "101"; // use string argument
int     f = 2 , // initial number base
        t = 10; // end number base

int numberInt = 13; // prime number for test


string convertAny(const string &str,int m,int n)
{
	const char table[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int s = str.size();
	int *data = new int[n];
	for(int i = 0;i < s;++i)
		if( '0' <= str[i] && str[i] <= '9')
			data[i] = str[i] - '0';
		else if('a' <= str[i] && str[i] <= 'z')
			data[i] = str[i] - 'a' + 10;
		else if('A' <= str[i] && str[i] <= 'Z')
			data[i] = str[i] - 'A' + 10;

	string ans;
	for(int first_not_zero = 0;first_not_zero != s;)
	{
		int r = 0;//r is remainder
		for(int i = first_not_zero;i < s;++i)
		{
			r = r * m + data[i];
			data[i] = r / n;
			r %= n;
		}
		ans.push_back(table[r]);
		for(;!data[first_not_zero] && first_not_zero < s;++first_not_zero);
	}
	delete[] data;
	ans.assign(ans.rbegin(), ans.rend());//reverse the ans
	return ans;
}

string isPrime(int n, int i = 2)
{
    // Base cases
    if (n <= 2)
        return (n == 2) ? "Yes" : "No";
    if (n % i == 0)
        return "No";
    if (i * i > n)
        return "Yes";

    // Check for next divisor
    return isPrime(n, i + 1);
}

double Min(double A[], int n){

    if (n == 1)
        return A[0];
    return min(A[n-1] , Min(A,n - 1));

}

int main()
{
    cout << "Recursive Functions" << endl;
    cout << endl;

    cout << "Min() \n# Find minimal element in the array." << endl;
    cout << endl;


    int n = sizeof(arrayList)/sizeof(arrayList[0]);
    cout <<"Minimal element of array - "<< (double) Min(arrayList,n)<< endl;
    cout << endl;

    cout << "convertAny() \n# Convert number into another base." << endl;
    cout << endl;

    cout << "Convert number "<<number <<" with base-"<<f <<" to base-"<<t<<" - "<<convertAny(number, f, t)<< endl;
    cout << endl;

    cout << "isPrime() \n# Check if number is prime." << endl;
    cout << endl;


    cout << numberInt << " is Prime : "<< isPrime(numberInt) << endl;
    cout << endl;
    return 0;


}


