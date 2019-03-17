#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <fstream>
using namespace std;

class Edge
{
public:
	int from;
	int to;
	long long weight;
	int id;
	Edge(int a, int b, long long c, int d)
	{
		from = a;
		to = b;
		weight = c;
		id = d;
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

int prank[1005];
int used[25005];
int parent[1005];
vector<Edge> G;

int Find(int p)
{
	if (p == parent[p])
		return p;
	else
		return Find(parent[p]);
}

bool Union(int a, int b)
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
	return 1;
}

int countEdge;

long long Kruskal(int start, int end, int num)
{
	long long res = 0;
	for (int i = start; i < end; i++)
	{
		if (Find(G[i].from) != Find(G[i].to))
		{
			Union(G[i].from, G[i].to);
			res += G[i].weight;
			G[i].id = 1;
			countEdge++;
		}
	}
	int p = Find(0);
	return res;
}

inline void initializeP()
{
	for (int i = 0; i < 1005; i++)
		parent[i] = i;
}

int main()
{
	//ofstream fout("out.txt");
	int n, m, a, b;
	long long w;
	while (scanf("%d%d", &n, &m))
	{
		countEdge = 0;
		if (n == 0 && m == 0)
			break;
		memset(prank, 0, sizeof(prank));
		memset(used, 0, sizeof(used));
		long long res = 0;
		G.clear();
		initializeP();
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> w;
			G.push_back({ a,b,w,0 });
		}
		sort(G.begin(), G.end());
		res = Kruskal(0, m, n);
		if (m == 0)
			printf("\\(^o^)/ pray to god\n");
		else if (countEdge == n - 1)
		{
			int isfirst = 1;
			printf("Min cost: %d\n", res);
			for (int i = 0; i < m; i++)
			{
				if (!G[i].id)
				{
					if (isfirst)
					{
						isfirst = 0;
						printf("%d", G[i].weight);
					}
					else
						printf(" %d", G[i].weight);
				}
			}
			printf("\n");
		}
		else
		{
			printf("\\(^o^)/ pray to god\n");
		}
	}
	return 0;
}
