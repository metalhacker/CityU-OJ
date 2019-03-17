#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

int dp[51][51][51][51];
char grid[51][51];

int mymax(int a, int b, int c, int d, int e)
{
	int res = a;
	res = max(res, b);
	res = max(res, c);
	res = max(res, d);
	res = max(res, e);
	return res;
}

bool check(int a, int b, int c, int d)
{
	for (int i = a; i <= a + c; i++)
	{
		if (grid[i][b] != '0')
			return 0;
	}
	for (int i = a; i <= a + c; i++)
	{
		if (grid[i][b + d] != '0')
			return 0;
	}
	for (int i = b; i <= b + d; i++)
	{
		if (grid[a][i] != '0')
			return 0;
	}
	for (int i = b; i <= b + d; i++)
	{
		if (grid[a + c][i] != '0')
			return 0;
	}
	return 1;
}

int main()
{
	int cases, row, col;
	cin >> cases;
	for (int t = 1; t <= cases; t++)
	{
		cin >> row;
		for (int i = 0; i < row; i++)
		{
			cin >> grid[i];
		}
		col = strlen(grid[0]);
		memset(dp, 0, sizeof(dp));
		for (int k = 2; k < row; k++)
		{
			for (int l = 2; l < col; l++)
			{
				for (int i = 0; i < row - k; i++)
				{
					for (int j = 0; j < col - l; j++)
					{
						dp[i][j][i + k][j + l] = mymax(dp[i][j][i + k][j + l], dp[i + 1][j][i + k][j + l],
							dp[i][j + 1][i + k][j + l], dp[i][j][i + k][j + l - 1], dp[i][j][i + k - 1][j + l]);
						if (check(i, j, k, l))
							dp[i][j][i + k][j + l] = max(dp[i][j][i + k][j + l], dp[i + 1][j + 1][i + k - 1][j + l - 1] + 1);
					}
				}
			}
		}
		cout << "Case #" << t << ": " << dp[0][0][row - 1][col - 1] << endl;
	}
	return 0;
}
