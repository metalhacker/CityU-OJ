#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <fstream>
#include <stack>
#include <cstdio>
using namespace std;
typedef double ll;

class Point
{
public:
	ll x;
	ll y;
	int index;
	Point()
	{
		x = 0;
		y = 0;
		index = 0;
	}
	Point(ll a, ll b, int in)
	{
		x = a;
		y = b;
		index = in;
	}
	bool operator < (const Point &another) const
	{
		return y < another.y;
	}
};



double getAngle(Point p1, Point p2, Point p3)
{
	double res = 0.0;
	double t1 = (p2.x - p1.x)*(p3.x - p2.x) + (p2.y - p1.y)*(p3.y - p2.y);
	double t2 = hypot(p2.x - p1.x, p2.y - p1.y)*hypot(p3.x - p2.x, p3.y - p2.y);
	res = t1 / t2;
	return res;
}

ll cross(Point p1, Point p2)
{
	ll product = (p1.x*p2.y - p2.x*p1.y);
	return product;
}

ll calculate(vector<Point> v)
{
	ll res = ll(0);
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
		{
			res += cross(v[i], v[0]);
			continue;
		}
		res += cross(v[i], v[i + 1]);
	}
	res = res / ll(2);
	return res;
}

int main() {
	int n, t = 0;
	ll a, b;
	while (cin >> n)
	{
		vector<Point> G;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			G.push_back({ a,b,i });
		}

		ll poly = calculate(G);

		int left = 0;
		for (int i = 0; i < n; i++)
		{
			if (G[i].y < G[left].y)
				left = i;
		}
		Point start = { G[left].x + 1, G[left].y, -1 };
		stack <Point> q;
		q.push(start);
		q.push(G[left]);
		while (true)
		{
			double maximum = -5.1;
			int temp = 0;
			Point p1 = q.top(); q.pop();
			Point p2 = q.top();
			q.push(p1);
			for (int i = 0; i < n; i++)
			{
				if (i == p1.index)
					continue;
				double td = getAngle(p2, p1, G[i]);
				if (td >= maximum)
				{
					if (td == maximum)
					{
						if (hypot((G[i].x - p1.x), (G[i].y - p1.y)) <= hypot((G[temp].x - p1.x), G[temp].y - p1.y))
						{
							continue;
						}
					}
					temp = i;
					maximum = td;
				}
			}
			if (temp != left)
				q.push(G[temp]);
			else
				break;
		}
		vector<Point> c;
		int tt = q.size();
		for (int i = 0; i < tt - 1; i++)
		{
			c.push_back(q.top()); q.pop();
		}
		ll con = calculate(c);
		ll answer = 1.0 - fabs(poly / con);
		answer *= ll(100);
		printf("Tile #%d\n", ++t);
		printf("Wasted Space = %.2lf %%\n\n", answer);
	}
	system("pause");
	return 0;
}
