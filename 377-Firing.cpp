#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long int ll;
#define inf ll(0x3f3f3f3f)

//int res[10005][10005];
ll parent[100005];
ll vis[100005];
ll head[100005];
ll dis[100005];
ll cur[100005];
ll s, t, n, m, ecnt, ncnt = 0;

class Edge
{
public:
	ll to, next;
	ll res;
	Edge(ll a, ll b, ll c) :to(a), res(b), next(c) {};
	Edge() :Edge(0, 0, 0) {};
};

Edge e[200050];

void addEdge(ll from, ll to, ll w)
{
	e[ecnt] = { to, w, head[from] };
	head[from] = ecnt++;
	e[ecnt] = { from, 0, head[to] };
	head[to] = ecnt++;
}

ll bfs()
{
	memset(dis, -1, sizeof(dis));
	queue<ll> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty())
	{
		ll temp = q.front();
		if (temp == t)
			return dis[t];
		q.pop();
		for (ll i = head[temp]; i != -1; i = e[i].next)
		{
			if (dis[e[i].to] == -1 && e[i].res > 0)
			{
				q.push(e[i].to);
				dis[e[i].to] = dis[temp] + 1;
			}
		}
	}
	return (dis[t] != -1);
}

ll dfs(ll p, ll flow)
{
	if (p == t)
		return flow;
	for (ll& i = cur[p]; i != -1; i = e[i].next)
	{
		if (e[i].res > 0 && dis[e[i].to] > dis[p])
		{
			ll currflow = dfs(e[i].to, min(flow, e[i].res));
			if (currflow > 0)
			{
				e[i].res -= currflow;
				e[i ^ 1].res += currflow;
				return currflow;
			}
		}
	}
	return ll(0);
}

ll dinic()
{
	ll mf = ll(0);
	while (bfs())
	{
		memcpy(cur, head, sizeof(head));
		mf += dfs(s, inf);
	}
	return mf;
}

void count(ll p)
{
	for (ll i = head[p]; i != -1; i = e[i].next)
	{
		if (!vis[e[i].to] && e[i].res > 0)
		{
			vis[e[i].to] = 1;
			ncnt++;
			count(e[i].to);
		}
	}
}

int main()
{
	while (cin >> n >> m)
	{
		memset(head, -1, sizeof(head));
		memset(dis, -1, sizeof(dis));
		ncnt = 0;
		ll temp;
		ll sum = 0;
		s = 0; t = n + 1;
		for (ll i = 1; i <= n; i++)
		{
			cin >> temp;
			if (temp > 0)
			{
				addEdge(s, i, temp);
				sum += temp;
			}
			else
			{
				addEdge(i, t, -temp);
			}
		}
		ll p1, p2;
		for (ll i = 0; i < m; i++)
		{
			cin >> p1 >> p2;
			addEdge(p1, p2, inf);
		}
		memset(vis, 0, sizeof(vis));
		ll res = dinic();
		count(s);
		cout << ncnt - 1 << " " << sum - res << endl;
	}
	system("pause");
	return 0;
}
