#include<iostream>
#include<cmath>
using namespace std;

int submerged[105][105];
int cnt;

void DFS(int r, int c)
{
	if (submerged[r][c] == 0)
		return;
	else
	{
		submerged[r][c] = 0;
		cnt++;
		DFS(r - 1, c);
		DFS(r + 1, c);
		DFS(r, c - 1);
		DFS(r, c + 1);
		return;
	}
}

int main()
{
	int m, n, k;
	while (cin >> m >> n >> k)
	{
		for (int i = 0; i < 104; i++)
			for (int j = 0; j < 104; j++)
				submerged[i][j] = 0;
		while (k > 0)
		{
			k--;
			int r, c;
			cin >> r >> c;
			submerged[r][c] = 1;
		}
		int res = 0;
		cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				DFS(i, j);
				if (res < cnt)
					res = cnt;
				cnt = 0;
			}	
		}
		cout << res << endl;
	}
	return 0;
}
