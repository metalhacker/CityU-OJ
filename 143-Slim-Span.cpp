#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

class Edge
{
public:
	int from;
	int to;
	int weight;
	Edge(int a, int b, int c)
	{
		from = a;
		to = b;
		weight = c;
	}
	bool operator < (const Edge &another) const
	{
		if (weight != another.weight)
			return weight < another.weight;
		else if (from != another.from)
			return from < another.from;
		else
			return to < another.to;
	}
};

int united[105];
int parent[105];
vector<Edge> G;

int Find(int p)
{
	if (p == parent[p])
		return p;
	else
		return Find(parent[p]);
}

void Union(int a, int b)
{
	int aRoot = Find(a);
	int bRoot = Find(b);
	if (aRoot != bRoot)
		parent[aRoot] = bRoot;
}

int Kruskal(int start, int end, int num)
{
	bool res = 1;
	for (int i = start; i < end; i++)
	{
		res = 1;
		Union(G[i].from, G[i].to);
		int p = Find(1);
		for (int j = 2; j <= num; j++)
		{
			if (Find(j) != p)
			{
				res = 0;
				break;
			}
		}
		if (res)
		{
			return G[i].weight - G[start].weight;
		}
	}
	return 99999999;
}

inline void initializeP()
{
	for (int i = 0; i < 105; i++)
		parent[i] = i;
}

int main()
{
	int n, m, a, b, w;
	while (scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0)
			break;
		G.clear();
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &w);
			G.push_back({ a,b,w });
		}
		if (n == 2 && m == 1)
		{
			printf("0\n");
			continue;
		}
		sort(G.begin(), G.end());
		int minimum = 99999999;
		for (int i = 0; i < m; i++)
		{
			initializeP();
			minimum = min(minimum, Kruskal(i, m, n));
		}
		if (minimum != 99999999)
		{
			printf("%d\n", minimum);
		}
		else
			printf("-1\n");
	}
	//system("pause");
	return 0;
}
