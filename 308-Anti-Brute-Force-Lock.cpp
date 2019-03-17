#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <fstream>
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

class Node
{
public:
	int a, b, c, d, value;
	Node(int num)
	{
		value = num;
		a = num / 1000;
		b = (num / 100) % 10;
		c = (num / 10) % 10;
		d = num % 10;
	}
	int getDis(Node another)
	{
		int res = 0;
		res += min(abs(a - another.a), min(abs(a + 10 - another.a), abs(another.a + 10 - a)));
		res += min(abs(b - another.b), min(abs(b + 10 - another.b), abs(another.b + 10 - b)));
		res += min(abs(c - another.c), min(abs(c + 10 - another.c), abs(another.c + 10 - c)));
		res += min(abs(d - another.d), min(abs(d + 10 - another.d), abs(another.d + 10 - d)));
		return res;
	}
	bool operator < (const Node &another) const
	{
		return value < another.value;
	}
};

int prank[10005];
int parent[10005];
vector<Edge> G;
vector<Node> N;

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
		return 0;
	}
	return 1;
}

int Kruskal(int start, int end, int num)
{
	int res = 0;
	for (int i = start; i < end; i++)
	{
		if (Find(G[i].from) != Find(G[i].to))
		{
			Union(G[i].from, G[i].to);
			res += G[i].weight;
		}
	}
	return res;
}

inline void initializeP()
{
	for (int i = 0; i < 10005; i++)
		parent[i] = i;
}

int main()
{
	//ofstream fout("out.txt");
	int total;
	int n, a, b;
	int cases = 1;
	scanf("%d", &total);
	while (total--)
	{
		int cnt = 0;
		int res = 0;
		scanf("%d", &n);
		G.clear();
		N.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			N.push_back({ a });
			parent[a] = a;
		}
		sort(N.begin(), N.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				G.push_back({ N[i].value, N[j].value, N[i].getDis(N[j]) });
				cnt++;
			}
		}
		sort(G.begin(), G.end());
		//initializeP();
		int temp = 99999999;
		Node zero = { 0 };
		res = Kruskal(0, cnt, n);
		for (int i = 0; i < n; i++)
		{
			temp = min(temp, zero.getDis(N[i]));
		}
		res += temp;
		printf("%d\n", res);
		//fout << res << endl;
		cases++;
	}
	//system("pause");
	return 0;
}
