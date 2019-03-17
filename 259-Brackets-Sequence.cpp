#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
#define INF 666
using namespace std;

int dp[102][102];

int main()
{
	int t;
	bool isfirst = 1;
	cin >> t;
	string brackets;
	cin.ignore(1);
	while (t--)
	{
		getline(cin, brackets);
		if (brackets == "")
			getline(cin, brackets);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < brackets.length(); i++)
			dp[i][i] = 1;
		for (int jiange = 1; jiange < brackets.length(); jiange++)
		{
			for (int i = 0; i + jiange < brackets.length(); i++)
			{
				int j = i + jiange;
                                dp[i][j] = INF;
				if ((brackets[i] == '('&&brackets[j] == ')') || (brackets[i] == '['&&brackets[j] == ']'))
					dp[i][j] = dp[i + 1][j - 1];
				for (int k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j]));
			}
		}
		if (isfirst)
			isfirst = 0;
		else
			cout << endl;
		cout << dp[0][brackets.length() - 1] + brackets.length() << endl;
	}
	return 0;
}
