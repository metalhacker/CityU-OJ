#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<long long> > seats;
vector<vector<long long> > reserved;
vector<long long> inputs[50];

int main()
{
	int flag = 0;
	long long t, n, m, c, res, temp;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		res = n * (m - 1);
		cin >> c;
		for (long long i = 0; i < c; i++) 
		{
			cin >> temp;
			inputs[i].push_back(temp);
		}
		for (long long i = 0; i < c; i++)
		{
			cin >> temp;
			inputs[i].push_back(temp);
		}
		for (long long i = 0; i < c; i++)
		{
			seats.push_back(inputs[i]);
		}
		for (long long i = 0; i < c; i++)
		{
			reserved.push_back(seats.back());
			seats.pop_back();
			res -= 2;
			if (reserved.back()[1] == 1 || reserved.back()[1] == m)
				res += 1;
			vector<long long> helper1 = { reserved.back()[0],reserved.back()[1] - 1 };
			vector<long long> helper2 = { reserved.back()[0],reserved.back()[1] + 1 };
			if (find(reserved.begin(), reserved.end(), helper1) != reserved.end())
				res += 1;
			if (find(reserved.begin(), reserved.end(), helper2) != reserved.end())
				res += 1;
		}
		if (res < 0)
			res = 0;
		seats.clear();
		reserved.clear();
		for (long long i = 0; i < 50; i++)
			inputs[i].clear();
		printf("Case #%d: %lld\n", ++flag , res);
	}
	return 0;
}
