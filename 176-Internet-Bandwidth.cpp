#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 999999
using namespace std;

int cap[105][105];
int res[105][105];
int parent[105];
bool vis[105];
int s, t, n;

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
		for (int i = 1; i <= n; i++)
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
	int cases = 0, m, t1, t2, t3;
	while (cin >> n)
	{
		if (n == 0)
			break;
		memset(cap, 0, sizeof(cap));
		memset(res, 0, sizeof(res));
		cin >> s >> t >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> t1 >> t2 >> t3;
			cap[t1][t2] += t3;
			cap[t2][t1] += t3;
			res[t1][t2] = cap[t1][t2];
			res[t2][t1] = cap[t2][t1];
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
		printf("Network %d\nThe bandwidth is %d.\n\n", ++cases, mf);
	}
	system("pause");
	return 0;
}
