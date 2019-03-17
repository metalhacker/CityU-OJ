#include <iostream>
using namespace std;

int coins[] = { 1,5,10,25,50 };
int dp[7500];

int main()
{
	for (int i = 0; i < 7500; i++)
		dp[i] = 0;
	dp[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = coins[i]; j < 7500; j++)
			dp[j] += dp[j - coins[i]];
	int money;
	while (cin >> money)
	{
		cout << dp[money] << endl;
	}
	return 0;
}
