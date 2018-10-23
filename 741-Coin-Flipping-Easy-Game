#include <iostream>
#include <string.h>
#include <bitset>
using namespace std;

int count(char*str, int m)
{
	int res0 = 0;
	int res1 = 0;
	for (int i = 0; i < m; i++)
	{
		if (str[i] == '1')
			res1++;
		else
			res0++;
	}
	if (res0 > res1)
		return res0;
	else
		return res1;
}

void flip(char**coins, int n, int j)
{
	for (int i = 0; i < n; i++)
	{
		if (coins[i][j] == '0')
			coins[i][j] = '1';
		else
			coins[i][j] = '0';
	}
}

int mypow(int a, int b)
{
	int res = 1;
	for (int i = 0; i < b; i++)
		res *= a;
	return res;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		char **coins = new char*[n];
		for (int i = 0; i < n; i++)
		{
			coins[i] = new char[m];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> coins[i];
		}
		char**origin = new char*[n];
		for (int i = 0; i < n; i++)
		{
			origin[i] = new char[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				origin[i][j] = coins[i][j];
		int times = mypow(2, m);
		int maximum = 0;
		for (int i = 0; i < times; i++)
		{
			bitset<10> bintimes(i);
			for (int j = 0; j < m; j++)
			{
				//int k = 0;
				if (bintimes[j] == 1)
				{
					flip(coins, n, j);
				}
				//k++;
			}
			int temp = 0;
			for (int i = 0; i < n; i++)
				temp += count(coins[i], m);
			if (temp > maximum)
				maximum = temp;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					coins[i][j] = origin[i][j];
		}
		cout << maximum << endl;
	}
	return 0;
}
