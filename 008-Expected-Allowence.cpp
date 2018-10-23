#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int sum = 0;

void cal(int x, int n, int m, int k, int *res)
{
	if (x == n)
	{
		if (sum - 1 > k)
		{
			res[sum]++;
		}
		else
		{
			res[k + 1]++;
		}
		return;
	}
	else
	{
		for (int i = 1; i <= m; i++)
		{
			sum += i;
			cal(x + 1, n, m, k, res);
			sum -= i;
		}
	}
}

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		if (n == 0 && m == 0 && k == 0)
			break;
		int res[10000] = { 0 };
		int total = 1;
		cal(0, n, m, k, res);
		for (int i = 0; i < n; i++)
		{
			total *= m;
		}
		int all = 0;
		for (int i = k + 1; i <= m*n; i++)
		{
			all += res[i] * (i - k);
		}
		cout << fixed << setprecision(8) << all * 1.0 / total << endl;
	}
}
