#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#define INF 999999
using namespace std;

int dis[1000][1000];
int path[1000][1000];
int cost[1000];

int main()
{
	int cases, n, temp, c1, c2;
	bool isfirst = 1;
	cin >> cases;
	string line;
	cin.ignore(2);
	while (cases > 0)
	{
		n = 0;
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 1000; j++)
				path[i][j] = j;
		cases--;
		getline(cin, line);
		stringstream sline(line);
		while (sline >> temp)
		{
			if (temp < 0)
				temp = INF;
			dis[0][n] = temp;
			n++;
		}
		for (int i = 1; i < n; i++)
		{
			getline(cin, line);
			stringstream sline(line);
			for (int j = 0; j < n; j++)
			{
				sline >> temp;
				if (temp < 0)
					temp = INF;
				dis[i][j] = temp;
			}
		}
		getline(cin, line);
		stringstream ssline(line);
		for (int i = 0; i < n; i++)
			ssline >> cost[i];
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (dis[i][j] > (dis[i][k] + dis[k][j] + cost[k]))
					{
						dis[i][j] = dis[i][k] + dis[k][j] + cost[k];
						path[i][j] = path[i][k];
					}
				}
			}
		}
		while (getline(cin, line))
		{
			if (line == "")
				break;
			if (isfirst == 1)
				isfirst = 0;
			else
				printf("\n");
			stringstream sline(line);
			sline >> c1 >> c2;
			printf("From %d to %d :\n", c1, c2);
			printf("Path: %d", c1);
			c1--; c2--;
			int cost = dis[c1][c2];
			while (c1 != c2)
			{
				printf("-->%d", path[c1][c2] + 1);
				c1 = path[c1][c2];
			}
			printf("\nTotal cost : %d\n", cost);
		}
	}
	return 0;
}
