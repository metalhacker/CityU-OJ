#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 9999999
using namespace std;

pair<int, int> robots[105];
//int cap[250][250];
int res[250][250];
int vis[250];
int parent[250];
int l, w, n, d, c = 0, x, y, s, t;

bool findPath()
{
	memset(vis, 0, sizeof(vis));
	memset(parent, 0, sizeof(parent));
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int point = q.front();
		q.pop();
		if (vis[point])
			continue;
		else 
			vis[point] = 1;
		if (vis[t])
			break;
		for (int i = 0; i <= t; i++)
		{
			if (!vis[i] && res[point][i] > 0)
			{
				q.push(i);
				parent[i] = point;
			}
		}
	}
	return vis[t];
}

int main()
{
	while (cin >> l >> w >> n >> d)
	{
		s = 2 * n;
		t = s + 1;
		//memset(cap, 0, sizeof(cap));
		memset(res, 0, sizeof(res));
		if (l == 0 && w == 0 && n == 0 && d == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			robots[i] = { x, y };
		}
		for (int i = 0; i < n; i++)
		{
			if (w - robots[i].second <= d)
			{
				//cap[s][i] = 1;
				//cap[i][s] = 0;
				res[s][i] = 1;
				res[i][s] = 0;
			}
			if (robots[i].second <= d)
			{
				//cap[t][i + n] = 0;
				//cap[i + n][t] = 1;
				res[t][i + n] = 0;
				res[i + n][t] = 1;
			}
			//add edge
			//cap[i][i + n] = 1;
			//cap[i + n][i] = 0;
			res[i][i + n] = 1;
			res[i + n][i] = 0;
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if ((robots[i].first - robots[j].first) * (robots[i].first - robots[j].first) + (robots[i].second - robots[j].second) * (robots[i].second - robots[j].second) <= d * d * 4)
				{
					if (robots[i].second >= robots[j].second)
					{
						//cap[i + n][j] = 1;
						//cap[j][i + n] = 0;
						res[i + n][j] = 1;
						res[j][i + n] = 0;
					}
				}
			}
		}
		int mf = 0, pf;
		while (findPath())
		{
			pf = INF;
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
		printf("Case %d: %d\n", ++c, mf);
	}
	return 0;
}
