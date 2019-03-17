#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
	int from;
	int to;
	int dis;
	Edge(int a, int b, int c)
	{
		from = a;
		to = b;
		dis = c;
	}
	bool operator < (const Edge& another) const
	{
		return dis > another.dis;
	}
};

vector<Edge>G;
int parent[505];
int prank[505];

int Find(int p)
{
	if (p == parent[p])
		return p;
	else
		return parent[p] = Find(parent[p]);
}

void Union(int a, int b)
{
	int aRoot = Find(a);
	int bRoot = Find(b);
	if (aRoot != bRoot)
	{
		if (prank[aRoot] < prank[bRoot])
			parent[aRoot] = bRoot;
		else if (prank[aRoot] == prank[bRoot])
		{
			prank[aRoot]++;
			parent[bRoot] = aRoot;
		}
		else
			parent[bRoot] = aRoot;
	}
}

inline void init()
{
	for (int i = 0; i < 505; i++)
		parent[i] = i;
	memset(prank, 0, sizeof(prank));
}

int main()
{
	int n, m, a, b, c;
	while (cin >> n >> m)
	{
		init();
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			G.push_back({ a,b,c });
		}
		sort(G.begin(), G.end());
		int ppa = G[0].dis;
		for (int i = 0; i < G.size(); i++)
		{
			if (G[i].dis != ppa)
				break;
			Union(G[i].from, G[i].to);
		}
		int maxNum = 0;
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (parent[i] != i)
				continue;
			else
			{
				temp = 0;
				for (int j = 1; j <= n; j++)
				{
					if (Find(j) == i)
						temp++;
				}
				maxNum = max(maxNum, temp);
			}
		}
		cout << maxNum << endl;
		G.clear();
	}
	return 0;
}
