#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 999999
using namespace std;

int dis[105];
int map[105][105];
bool visited[105];
int level[105];
int parent[105];

int getmaxl(int a)
{
	int maxl = 0;
	int temp = a;
	while (temp != -1)
	{
		maxl = max(maxl, level[temp]);
		temp = parent[temp];
	}
	return maxl;
}

int getminl(int a)
{
	int minl = INF;
	int temp = a;
	while (temp != -1)
	{
		minl = min(minl, level[temp]);
		temp = parent[temp];
	}
	return minl;
}

class Vertex
{
public:
	int point;
	int distance;
	int maxl;
	int minl;
	Vertex(int a, int b, int c, int d)
	{
		point = a;
		distance = b;
		maxl = c;
		minl = d;
	}
	bool operator < (const Vertex &another) const
	{
		return distance > another.distance;
	}
};


int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		for (int i = 0; i < 105; i++)
		{
			dis[i] = INF;
		}
		dis[n] = 0;
		for (int i = 0; i < 105; i++)
		{
			for (int j = 0; j < 105; j++)
			{
				map[i][j] = INF;
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(level, -1, sizeof(level));
		memset(parent, -1, sizeof(parent));
		map[n][n] = 0;
		for (int i = 0; i < n; i++)
		{
			int p, v;
			cin >> map[n][i] >> level[i] >> p;
			while (p--)
			{
				cin >> v;
				cin >> map[v - 1][i];
			}
		}
		priority_queue<Vertex> pq;
		pq.push({ n,0,0,INF });
		while (!pq.empty())
		{
			Vertex vertex = pq.top();
			int tnode = vertex.point, tdis = vertex.distance, tmax = vertex.maxl, tmin = vertex.minl;
			pq.pop();
			/*if (visited[tnode])
				continue;
			visited[tnode] = 1;*/
			for (int i = 0; i < n; i++)
			{
				if (dis[i] > tdis + map[tnode][i])
				{
					if (((abs(level[i] - tmax) <= m) && (abs(level[i] - tmin) <= m)) || tnode == n)
					{
						dis[i] = tdis + map[tnode][i];
						pq.push({ i,dis[i],max(level[i],tmax),min(level[i],tmin) });
					}
				}
			}
		}
		cout << dis[0] << endl;
	}
	return 0;
}
