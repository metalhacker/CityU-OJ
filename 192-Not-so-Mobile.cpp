#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int getBalance(string holder)
{
	int a, b, c, d;
	istringstream myStream;
	myStream.str(holder);
	myStream >> a >> b >> c >> d;
	if (a == 0 || c == 0)
	{
		if (a == 0 && c == 0)
		{
			string holder1;
			string holder2;
			getline(cin, holder1);
			int aa = getBalance(holder1);
			getline(cin, holder2);
			int cc = getBalance(holder2);
			if (aa == -1 || cc == -1)
				return -1;
			else if (aa * b == cc * d)
				return (aa + cc);
			else
				return -1;
		}
		else if (a == 0)
		{
			string holder1;
			getline(cin, holder1);
			int aa = getBalance(holder1);
			if (aa * b == c * d)
				return (aa + c);
			else
				return -1;
		}
		else
		{
			string holder2;
			getline(cin, holder2);
			int cc = getBalance(holder2);
			if (a * b == cc * d)
				return (a + cc);
			else
				return -1;
		}
	}
	else
	{
		if (a * b == c * d)
			return (a + c);
		else
			return -1;
	}
}

int main()
{
	
	string hold;
	int cases;
	cin >> cases;
	cin.ignore(1);
	getline(cin, hold);
	for (int i = 0; i < cases; i++)
	{
		while (getline(cin, hold))
		{
			if (hold.empty())
				break;
			if (getBalance(hold) < 0)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
			if (i < cases - 1)
				cout << endl;
		}
	}
	return 0;
}
