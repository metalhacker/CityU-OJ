#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1002][1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= (int)str1.length(); i++)
		{
			for (int j = 1; j <= (int)str2.length(); j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		cout << dp[str1.length()][str2.length()] << endl;
	}
	return 0;
}
