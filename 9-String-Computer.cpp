#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define INF 23333
int dp[200][200];
int op[200][200];
string str1;
string str2;

void operate(int i, int j)
{
	if (i == 0 && j == 0) return;
	if (op[i][j] == 1)
	{
		operate(i - 1, j);
		printf("D%c%02d", str1[i - 1], j + 1);
	}
	else if (op[i][j] == 2)
	{
		operate(i, j - 1);
		printf("I%c%02d", str2[j - 1], j);
	}
	else if (op[i][j] == 3)
	{
		operate(i - 1, j - 1);
		printf("C%c%02d", str2[j - 1], j);
	}
	else
	{
		operate(i - 1, j - 1);
	}
}

int main()
{
	while (cin >> str1)
	{
		if (str1.compare("#") == 0)
			break;
		cin >> str2;
		int l1 = str1.length();
		int l2 = str2.length();
		for (int i = 0; i <= l1; i++)
			for (int j = 0; j <= l2; j++)
				dp[i][j] = INF;
		for (int i = 0; i <= l1; i++)
			for (int j = 0; j <= l2; j++)
				op[i][j] = 0;
		for (int i = 0; i <= l1; i++)
		{
			dp[i][0] = i;
			op[i][0] = 1;
		}
		for (int i = 0; i <= l2; i++)
		{
			dp[0][i] = i;
			op[0][i] = 2;
		}
		for (int i = 1; i <= l1; i++)
		{
			for (int j = 1; j <= l2; j++)
			{
				if (str1[i - 1] != str2[j - 1])
				{
					op[i][j] = 3;
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				if (dp[i][j] > dp[i - 1][j] + 1)
				{
					op[i][j] = 1;
					dp[i][j] = dp[i - 1][j] + 1;
				}
				if (dp[i][j] > dp[i][j - 1] + 1)
				{
					op[i][j] = 2;
					dp[i][j] = dp[i][j - 1] + 1;
				}
			}
		}
		operate(l1, l2);
		cout << "E" << endl;
	}
	return 0;
}
