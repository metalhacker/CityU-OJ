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
			return weight > another.weight;
		else if (from != another.from)
			return from > another.from;
		else
			return to > another.to;
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
		int p = Find(0);
		for (int j = 1; j < num; j++)
		{
			if (Find(j) != p)
			{
				res = 0;
				break;
			}
		}
		if (res)
		{
			return G[i].weight;
		}
	}
	return 0;
}

inline void initializeP()
{
	for (int i = 0; i < 105; i++)
		parent[i] = i;
}

int main()
{
	int total;
	int n, m, a, b, w;
	int cases = 1;
	scanf("%d", &total);
	while (total--)
	{
		scanf("%d%d", &n, &m);
		G.clear();
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &w);
			G.push_back({ a,b,w });
		}
		sort(G.begin(), G.end());
		int maximum = 0;
		initializeP();
		maximum = max(maximum, Kruskal(0, m, n));
		printf("Case #%d: %d\n", cases, maximum);
		cases++;
	}
	//system("pause");
	return 0;
}
