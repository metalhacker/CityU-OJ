#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 233

double x[201] = { 0 };
double y[201] = { 0 };
double dis[201][201];

int main()
{
	int num;
	int t = 0;
	while (cin >> num)
	{
		if (num == 0)
			break;
		for (int i = 0; i < num; i++)
			cin >> x[i] >> y[i];
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				dis[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		for (int k = 0; k < num; k++)
			for (int i = 0; i < num; i++)
				for (int j = 0; j < num; j++)
					dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
		printf("Scenario #%d\n", ++t);
		printf("Frog Distance = %.3f\n\n", dis[0][1]);
	}
	return 0;
}
