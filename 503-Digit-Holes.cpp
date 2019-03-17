#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int gethole(int num)
{
	int res = 0;
	while (num >= 0)
	{
		int temp = num % 10;
		num /= 10;
		if (num == 0)
			num = -1;
		switch (temp)
		{
		case 0: case 4: case 6: case 9:
			res += 1;
			break;
		case 8:
			res += 2;
			break;
		default:
			break;
		}
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << gethole(n) << endl;
	}
}
