#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int check(string str)
{
	int s = 0;
	int l = str.length();
	if (l == 0)
		return 0;
	if (l == 1)
	{
		if (str == "A")
			return 1;
	}
	else if ((str.at(s) == 'B') && (str.at(s + l - 1) == 'A'))
	{
		if (check(str.substr(s + 1, l - 2)) > 0)
			return 2;
	}
	else if ((str.at(s + l - 1) == 'B') && (str.at(s + l - 2) == 'A'))
	{
		if (check(str.substr(s, l - 2)) > 0)
			return 3;
	}
	return 0;
}

int main()
{
	int cases;
	cin >> cases;
	string cells;
	for (int i = 0; i < cases; i++)
	{
		cin >> cells;
		int stage = check(cells);
		if (stage == 0)
			cout << "MUTANT" << endl;
		else if (stage == 1)
			cout << "SIMPLE" << endl;
		else if (stage == 2)
			cout << "MUTAGENIC" << endl;
		else if (stage == 3)
			cout << "FULLY-GROWN" << endl;
	}
	//system("pause");
	return 0;
}
