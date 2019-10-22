#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1, x2, x3;
	int y1, y2, y3;
	float d1, d2, d3;

	cout << "Enter a points:" << endl;
	cout << "x1,y1 -> ";
	cin >> x1 >> y1;
	cout << "x2,y2 -> ";
	cin >> x2 >> y2;
	cout << "x3,y3 -> ";
	cin >> x3 >> y3;

	d1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	d2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	d3 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));

	cout << "d1 -> " << d1 << "| d2 -> " << d2 << "| d3 ->" << d3 << endl;

	if ((d1 + d2 <= d3) || (d2 + d3 <= d1) || (d1 + d3 <= d2))
	{
		cout << "exist";

		if ((x1 * (y2 - y1) - (x2 - x1) * y1) > 0 && (x2 * (y3 - y2) - (x3 - x2) * y2) > 0 && (x1 * (y1 - y3) - (x1 - x3) * y3) > 0)
		{
			cout << "(0,0) inside triagle" << endl;
		}
		else if (((x1 * (y2 - y1) - (x2 - x1) * y1) < 0 && (x2 * (y3 - y2) - (x3 - x2) * y2) < 0 && (x1 * (y1 - y3) - (x1 - x3) * y3) < 0))
		{
			cout << "(0,0) inside triagle" << endl;
		}
		else if ((x1 * (y2 - y1) - (x2 - x1) * y1) == 0 || (x2 * (y3 - y2) - (x3 - x2) * y2) == 0 || (x1 * (y1 - y3) - (x1 - x3) * y3) == 0)
		{
			cout << "(0,0) inside side of triagle" << endl;
		}
		else
		{
			cout << "(0,0) outside triagle" << endl;
		}
	}
	else
	{
		cout << "not exist";
	}

	return 0;
}
