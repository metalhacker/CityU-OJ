#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int cases;
	int digits = 0;
	int temp = 0;
	int valid = 0;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		valid = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> digits;
			valid += digits % 10;
			digits /= 10;
			temp = digits % 10;
			temp *= 2;
			valid += temp % 10;
			valid += temp / 10;
			digits /= 10;
			valid += digits % 10;
			digits /= 10;
			temp = digits % 10;
			temp *= 2;
			valid += temp % 10;
			valid += temp / 10;
		}
		if (valid % 10 == 0)
			cout << "Valid" << endl;
		else
			cout << "Invalid" << endl;
	}
	return 0;
}
