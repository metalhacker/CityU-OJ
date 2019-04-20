#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 999999
using namespace std;

int cap[1100][1100];
int res[1100][1100];
int parent[1100];
bool vis[1100];
int s, t, nk, np;

bool findPath()
{
	memset(vis, 0, sizeof(vis));
	memset(parent, 0, sizeof(parent));
	vis[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		vis[temp] = 1;
		if (vis[t])
			break;
		for (int i = 1; i <= t; i++)
		{
			if (!vis[i] && res[temp][i] > 0)
			{
				q.push(i);
				parent[i] = temp;
			}
		}
	}
	return vis[t];
}

int main() 
{
	int t1, t2, sum;
	while (cin >> nk >> np)
	{
		if (nk == 0 && np == 0)
			break;
		sum = 0;
		s = 0;
		t = nk + np + 1;
		memset(cap, 0, sizeof(cap));
		memset(res, 0, sizeof(res));
		for (int i = 1; i <= nk; i++)
		{
			cin >> cap[np + i][np + nk + 1];
			sum += cap[np + i][np + nk + 1];
			cap[np + nk + 1][np + i] = -cap[np + i][np + nk + 1];
			res[np + i][np + nk + 1] = cap[np + i][np + nk + 1];
			res[np + nk + 1][np + i] = cap[np + nk + 1][np + i];
		}
		for (int i = 1; i <= np; i++)
		{
			cap[i][0] = -1;
			cap[0][i] = -cap[i][0];
			res[i][0] = cap[i][0];
			res[0][i] = cap[0][i];
			cin >> t1;
			for (int j = 0; j < t1; j++)
			{
				cin >> t2;
				cap[i][np + t2] = 1;
				cap[np + t2][i] = -cap[i][np + t2];
				res[i][np + t2] = cap[i][np + t2];
				res[np + t2][i] = cap[np + t2][i];
			}
		}
		int mf = 0;
		while (findPath())
		{
			int pf = INF;
			for (int i = t; i != s; i = parent[i])
			{
				pf = min(pf, res[parent[i]][i]);
			}
			for (int i = t; i != s; i = parent[i])
			{
				res[parent[i]][i] -= pf;
				res[i][parent[i]] += pf;
			}
			mf += pf;
		}
		if (mf == sum)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	system("pause");
	return 0;
}
