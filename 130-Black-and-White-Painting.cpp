#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		else
		{
			if ((a - 7)*(b - 7) % 2 == 0)
			{
				cout << (a - 7)*(b - 7) / 2 << endl;
			}
			else
			{
				if (c == 1)
				{
					cout << (a - 7)*(b - 7) / 2 + 1<< endl;
				}
				else
				{
					cout << (a - 7)*(b - 7) / 2 << endl;
				}
			}
		}
	}
	return 0;
}
