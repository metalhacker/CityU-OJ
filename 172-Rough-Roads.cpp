#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <fstream>
#define INF 999999
using namespace std;

class Edge
{
public:
	int start;
	int end;
	int distance;
	int next;
	Edge()
	{
		start = 0;
		end = 0;
		distance = 0;
		next = 0;
	}
	void set(int s, int e, int d, int n)
	{
		start = s;
		end = e;
		distance = d;
		next = n;
	}
};

class Vertex
{
public:
	int destination;
	int distance;
	int status;
	Vertex(int a, int b, int c) { destination = a, distance = b, status = c; };
	void set(int a, int b, int c)
	{
		destination = a;
		distance = b;
		status = c;
	}
	bool operator < (const Vertex &another) const
	{
		return distance > another.distance;
	}

};

int dis[502][2];
int visited[502][2];
int total;
int front[502];
Edge edges[502 * 502];

int main()
{
	//ofstream fout("D:\\temp\\test.txt", ofstream::out);
	int n, r;
	int cases = 0;
	while (cin >> n >> r)
	{
		memset(dis, 30, sizeof(dis));
		memset(visited, 0, sizeof(visited));
		memset(front, -1, sizeof(front));
		int s, e, d;
		dis[0][1] = 0;
		for (int i = 0; i < r; i++)
		{
			cin >> s >> e >> d;
			edges[2 * i].set(s, e, d, front[s]);
			front[s] = 2 * i;
			edges[2 * i + 1].set(e, s, d, front[e]);
			front[e] = 2 * i + 1;
		}
		priority_queue<Vertex> pq;
		pq.push({ 0,0,1 });
		while (!pq.empty())
		{
			Vertex vertex = pq.top();
			//destination,distance,status
			pq.pop();
			if (visited[vertex.destination][vertex.status])
				continue;
			visited[vertex.destination][vertex.status] = 1;
			for (int i = front[vertex.destination]; i != -1; i = edges[i].next)
			{
				int dest = edges[i].end;
				if (dis[dest][vertex.status ^ 1] > dis[vertex.destination][vertex.status] + edges[i].distance)
				{
					dis[dest][vertex.status ^ 1] = dis[vertex.destination][vertex.status] + edges[i].distance;
					pq.push({ dest,dis[dest][vertex.status ^ 1],(vertex.status ^ 1) });
				}
			}
		}
		if (dis[n - 1][1] > INF)
			cout << "Set #" << (++cases) << endl << "?" << endl;
		else
			cout << "Set #" << (++cases) << endl << dis[n - 1][1] << endl;
	}
	//fout.close();
	return 0;
}
