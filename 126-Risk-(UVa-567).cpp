#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define INF 233

int dis[200][200];

int main()
{
	string str;
	int cases = 0;
	int num;
	while (cin >> num) {
		cases++;
		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 25; j++)
				dis[i][j] = INF;
		for (int i = 0; i < 25; i++)
			dis[i][i] = 0;
		int neighbor;
		for (int i = 1; i < 20; i++)
		{
			if (i != 1)
				cin >> num;
			for (int j = 0; j < num; j++)
			{
				cin >> neighbor;
				dis[i][neighbor] = 1;
				dis[neighbor][i] = 1;
			}
		}
		for (int k = 1; k <= 20; k++)
			for (int i = 1; i <= 20; i++)
				for (int j = 1; j <= 20; j++)
					dis[i][j] = dis[i][j] > (dis[i][k] + dis[k][j]) ? (dis[i][k] + dis[k][j]) : dis[i][j];
		cin >> num;
		int c1, c2;
		printf("Test Set #%d\n", cases);
		for (int i = 0; i < num; i++)
		{
			cin >> c1 >> c2;
			printf("%2d to %2d: %d\n", c1, c2, dis[c1][c2]);
		}
		puts("");
	}
	return 0;
}
