#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;
double EPSILON = 1e-8;

int main()
{
	double d, px, py, vx, vy;
	//ofstream fout("out.txt");
	while (cin >> d)
	{
		if (d < EPSILON)
			break;
		cin >> px >> py >> vx >> vy;
		if (fabs(px * vy - py * vx) > EPSILON)
		{
			//cout << fabs(px * vy - py * vx) << endl;
			cout << "impossible" << endl;
		}
		else
		{
			if (px * vx + py * vy < 0)
			{
				if (hypot(px, py) > d)
				{
					cout << "impossible" << endl;
				}
				else
				{
					cout << "possible" << endl;
				}
			}
			else
			{
				if (2.0 - hypot(px, py) > d)
				{
					cout << "impossible" << endl;
				}
				else
				{
					cout << "possible" << endl;
				}
			}
		}
	}
	//system("pause");
	return 0;
}
