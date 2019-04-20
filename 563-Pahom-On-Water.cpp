#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define EPSILON 1e-8
#define INF 9999999
using namespace std;

class pad
{
public:
	double f;
	int x;
	int y;
	int r;
	pad()
	{
		f = 0.0;
		x = 0;
		y = 0;
		r = 0;
	}
	pad(double ff, int a, int b, int c)
	{
		f = ff;
		x = a;
		y = b;
		r = c;
	}
};
pad pads[305];
//int cap[650][650];
int res[650][650];
int vis[650];
int parent[650];
int x, y, n, r, s, t;
double f;

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
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> n;
		s = n;
		t = s + 1;
		//memset(cap, 0, sizeof(cap));
		memset(res, 0, sizeof(res));
		for (int i = 0; i < n; i++)
		{
			cin >> f >> x >> y >> r;
			pads[i] = { f, x, y, r };
		}
		for (int i = 0; i < n; i++)
		{
			if (fabs(pads[i].f - 400.0) <= EPSILON)
			{
				//cap[s][i] = 2;
				//cap[i][s] = 0;
				res[s][i] = 2;
				res[i][s] = 0;
			}
			else if (fabs(pads[i].f - 789.0) <= EPSILON)
			{
				//cap[t][i] = 0;
				//cap[i][t] = 2;
				res[t][i] = 0;
				res[i][t] = 2;
			}
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if ((pads[i].x - pads[j].x) * (pads[i].x - pads[j].x) + (pads[i].y - pads[j].y) * (pads[i].y - pads[j].y) <= (pads[i].r + pads[j].r) * (pads[i].r + pads[j].r))
				{
					if (pads[i].f < pads[j].f)
					{
						//cap[i][j] = 1;
						//cap[j][i] = 0;
						res[i][j] = 1;
						res[j][i] = 0;
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
		if (mf == 2)
			printf("Game is VALID\n");
		else
			printf("Game is NOT VALID\n");
	}
	system("pause");
	return 0;
}
