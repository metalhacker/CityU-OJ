#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int knext[100005];

void getnext(string str)
{
	knext[0] = -1;
	int i = 0;
	int j = -1;
	while (i < (int)str.length())
	{
		if (j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			knext[i] = j;
		}
		else
			j = knext[j];
	}
}

int kmp(string str)
{	
	int i = 0, j = 0;
	string temp = str;
	reverse(temp.begin(), temp.end());
	getnext(temp);
	while (i < (int)str.length())
	{
		if (j == -1 || str[i] == temp[j])
		{
			i++;
			j++;
		}
		else
			j = knext[j];
	}
	return i - j;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int index = kmp(str) - 1;
		for (int i = index; i >= 0; i--)
		{
			str.push_back(str[i]);
		}
		cout << str << endl;
	}
	return 0;
}
