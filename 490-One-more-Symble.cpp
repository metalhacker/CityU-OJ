#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int mypow(int x, int y)
{
	int z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x;
	}
	return z;
}

int main()
{
	char str[1000];
	int num[500];
	for (int i = 0; i < 500; i++)
	{
		num[i] = -1;
	}
	char oper[500];
	while (cin >> str)
	{
		int numCount = 0;
		int operCount = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (isdigit(str[i]))
			{
				num[numCount] = (int)(str[i]-48);
				numCount++;
			}
			else
			{
				oper[operCount] = str[i];
				operCount++;
			}
		}
		oper[operCount] = '\0';
		for (int i = 0; i < strlen(oper); i++)
		{
			if (oper[i] == '^')
			{
				num[i] = mypow(num[i], num[i + 1]);
				num[i + 1] = -1;
			}
		}
		for (int i = 0; i < numCount; i++)
		{
			for (int j = 0; j < numCount-1; j++)
			{
				if (num[j] == -1)
					swap(num[j], num[j + 1]);
			}
		}
		for (int i = 0; i < strlen(oper); i++)
		{
			for (int j = 0; j < strlen(oper - 1); j++)
			{
				if (oper[j] == '^')
				{
					oper[j] = oper[j + 1];
					oper[j + 1] = '^';
				}
			}
		}
		for (int i = 0; i < numCount; i++)
		{
			if (oper[i] == '*')
			{
				num[i + 1] = num[i] * num[i + 1];
				num[i] = -1;
			}
		}
		for (int i = 0; i < numCount; i++)
		{
			for (int j = 0; j < numCount-1; j++)
			{
				if (num[j] == -1)
					swap(num[j], num[j + 1]);
			}
		}
		numCount = 0;
		int sum = 0;
		while (num[numCount] != -1)
		{
			sum += num[numCount];
			numCount++;
		}
		cout << sum << endl;
	}
	return 0;
}
