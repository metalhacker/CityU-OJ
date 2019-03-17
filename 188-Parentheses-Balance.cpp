#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

bool dp[150][150];

int main()
{
	//fstream fout("out.txt");
	int n;
	string str;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		memset(dp, 0, sizeof(dp));
		getline(cin, str);
		for (int j = 0; j <= str.length(); j+=2)
		{
			for (int i = 0; i + j <= str.length(); i++)
			{
				if (j == 0)
					dp[i][j] = 1;
				else
				{
					if ((str[i] == '('&&str[i + j - 1] == ')') || (str[i] == '['&&str[i + j - 1] == ']'))
					{
						if (dp[i + 1][j - 2])
							dp[i][j] = 1;
					}
					if(dp[i][j] == 0)
					{
						for (int k = 2; k <= j; k += 2)
						{
							if (dp[i][k] == 1 && dp[i + k][j - k] == 1)
							{
								dp[i][j] = 1;
								break;
							}
						}
					}
				}
			}
		}
		if (dp[0][str.length()])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
