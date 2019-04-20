#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>
#define INF 999999.0
using namespace std;

double sets[105];
double dp[105];

int main()
{
	double p;
	int n, s;
	int t = 0;
	while (cin >> p >> n)
	{
		for (int i = 0; i < 105; i++)
			sets[i] = INF;
		for (int i = 0; i < 105; i++)
			dp[i] = INF;
		t++;
		sets[1] = p;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> p;
			sets[s] = min(sets[s], p);
		}
		dp[0] = 0;
		for (int i = 1; i < 105; i++)
		{
			for (int j = 0; j < 105; j++)
			{
				if (i - j < 0)
					break;
				if (sets[j] != INF)
				{
					dp[i] = min(dp[i], dp[i - j] + sets[j]);
				}
			}
		}
		string line;
		cin.ignore(1);
		getline(cin, line);
		stringstream lin(line);
		printf("Case %d:\n", t);
		while (lin >> s)
		{
			printf("Buy %d for $%.2f\n", s, dp[s]);
		}
	}
	return 0;
}
