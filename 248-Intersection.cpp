#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
typedef long long int ll;

class Segment
{
public:
	ll xs, ys, xe, ye;
	Segment()
	{
		xs = ll(0);
		ys = ll(0);
		xe = ll(0);
		ye = ll(0);
	}
	Segment(ll a, ll b, ll c, ll d)
	{
		xs = a;
		ys = b;
		xe = c;
		ye = d;
	}
};

bool isCollide(Segment s1, Segment s2)
{
	ll A, B, C;
	A = s1.ye - s1.ys;
	B = s1.xs - s1.xe;
	C = s1.xe * s1.ys - s1.xs * s1.ye;
	ll S1, S2;
	S1 = A * s2.xs + B * s2.ys + C;
	S2 = A * s2.xe + B * s2.ye + C;
	if (S1 == 0 || S2 == 0)
	{
		return 1;
	}
	else if (S1 * S2 < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool special(Segment s1, Segment s2)
{
	ll A, B, C;
	A = s1.ye - s1.ys;
	B = s1.xs - s1.xe;
	C = s1.xe * s1.ys - s1.xs * s1.ye;
	ll S1, S2;
	S1 = A * s2.xs + B * s2.ys + C;
	S2 = A * s2.xe + B * s2.ye + C;
	if (S1 == 0 && S2 == 0)
	{
		if (min(s1.ye, s1.ys) > max(s2.ye, s2.ys) || min(s2.ye, s2.ys) > max(s1.ye, s1.ys) ||
			min(s1.xe, s1.xs) > max(s2.xe, s2.xs) || min(s2.xe, s2.xs) > max(s1.xe, s1.xs))
			return 0;
	}
	return 1;
}

int main()
{
	//ofstream fout("out.txt");
	int n;
	ll xs, ys, xe, ye, xl, yt, xr, yb, temp;
	cin >> n;
	while (n--)
	{
		int flag = 0;
		cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;
		if (xl > xr)
		{
			temp = xl;
			xl = xr;
			xr = temp;
		}
		if (yb > yt)
		{
			temp = yb;
			yb = yt;
			yt = temp;
		}
		Segment l = { xs,ys,xe,ye };
		Segment s1 = { xl,yb,xl,yt };
		Segment s2 = { xr,yb,xl,yb };
		Segment s3 = { xl,yt,xr,yt };
		Segment s4 = { xr,yb,xr,yt };
		if (isCollide(l, s1) && isCollide(s1, l) && special(l, s1))
		{
			flag = 1;
		}
		else if (isCollide(l, s2) && isCollide(s2, l) && special(l, s2))
		{
			flag = 1;
		}
		else if (isCollide(l, s3) && isCollide(s3, l) && special(l, s3))
		{
			flag = 1;
		}
		else if (isCollide(l, s4) && isCollide(s4, l) && special(l, s4))
		{
			flag = 1;
		}
		else if ((xs > xl) && (xs < xr) && (ys > yb) && (ys < yt) && (xe > xl) && (xe < xr) && (ye > yb) && (ye < yt))
		{
			flag = 1;
		}
		if (flag)
		{
			cout << "T" << endl;
		}
		else
		{
			cout << "F" << endl;
		}
	}
	system("pause");
	return 0;
}
