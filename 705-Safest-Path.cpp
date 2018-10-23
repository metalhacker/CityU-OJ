//Dijkstra
#include <stdio.h>
using namespace std;
double safe[300][300];
double res[300];
bool flag[300];
int n, s, t;

int main()
{
	while (~scanf("%d", &n))
	{
		scanf("%d%d", &s, &t);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%lf", &safe[i][j]);
		for (int i = 0; i < n; i++)
			res[i] = safe[s - 1][i];
		for (int i = 0; i < n; i++)
			flag[i] = 0;
		flag[s - 1] = 1;
		double max;
		int temp;

		for (int i = 0; i < n - 1; i++)
		{
			max = 0;
			for (int j = 0; j < n; j++)
			{
				if (!flag[j] && res[j] > max)
				{
					max = res[j];
					temp = j;
				}
			}
			flag[temp] = 1;
			for (int j = 0; j < n; j++)
			{
				if (!flag[j] && res[j] < res[temp] * safe[temp][j])
					res[j] = res[temp] * safe[temp][j];
			}
		}

		if (res[t - 1] == 0)
			printf("DANGER!\n");
		else
			printf("%.3lf\n", res[t - 1]);
	}
	return 0;
}

//I think this problem can also be solved with Floyd Algorithm, however always get an WA
//code is as following
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int n, s, t;
	while (cin >> n >> s >> t)
	{
		double safe[300][300];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> safe[i][j];
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (safe[i][j] < safe[i][k] * safe[k][j])
						safe[i][j] = safe[i][k] * safe[k][j];
		if (safe[s - 1][t - 1] < 1e-9)
			cout << "DANGER!" << endl;
		else
			cout << setprecision(3) << fixed << safe[s - 1][t - 1] << endl;
	}
	return 0;
}
