#include <iostream>
#include <algorithm>
using namespace std;

int obj[1002][2];
int dp[1002][32];

int main()
{
	for (int i = 0; i < 1002; i++)
		dp[i][0] = 0;
	int t, n, w, r;
	cin >> t;
	while (t > 0)
	{
		t--;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> obj[i][0] >> obj[i][1];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < 32; j++)
			{
				if (obj[i][1] <= j)
					dp[i][j] = max(dp[i - 1][j], obj[i][0] + dp[i - 1][j - obj[i][1]]);
				else if (obj[i][1] > j)
					dp[i][j] = dp[i - 1][j];
			}
		}
		cin >> r;
		int res = 0;
		for (int i = 0; i < r; i++)
		{
			cin >> w;
			res += dp[n][w];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 32; j++)
				dp[i][j] = 0;
			obj[i][0] = 0;
			obj[i][1] = 0;
		}
		cout << res << endl;
	}
}
