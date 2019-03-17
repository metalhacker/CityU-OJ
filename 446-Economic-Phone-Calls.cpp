#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

int dp[1002];
int mytime[1002][2];

int main()
{
	//ofstream fout("H:\\test.txt");
	int t;
	int temp;
	string line;
	string phone;
	char flag;
	stack<int> record;
	while (cin >> t)
	{
		cin.ignore(1);
		if (t == 0)
			break;
		memset(dp, 0, sizeof(dp));
		memset(mytime, 0, sizeof(mytime));
		for (int i = 0; i < t; i++)
		{
			getline(cin, line);
			for (int j = 0; j < line.length(); j++)
			{
				if (line[j] == ':')
					line[j] = ' ';
			}
			stringstream linein(line);
			linein >> temp;
			mytime[i][0] += temp * 1000000;
			linein >> temp;
			mytime[i][0] += temp * 10000;
			linein >> temp;
			mytime[i][0] += temp * 100;
			linein >> temp;
			mytime[i][0] += temp;
			linein >> phone;
			linein >> flag;
			mytime[i][1] = flag == '+' ? 1 : 0;
		}
		temp = mytime[t - 1][0];
		while (!record.empty())
			record.pop();
		int start = 0;
		int end = t - 1;
		while (mytime[start][1] != 1 && start <= end)
			start++;
		while (mytime[end][1] != 1 && start <= end)
			end--;
		for (int i = end; i < t - 1; i++)
		{
			if (mytime[i][0] >= mytime[i + 1][0])
				end = i + 1;
		}
		for (int i = end; i >= start; i--)
		{
			if (record.empty())
				record.push(mytime[i][0]);
			else 
			{
				if (mytime[i][1] == 1)
					record.push(mytime[i][0]);
				else if (i == end)
					record.push(mytime[i][0]);
				else if (mytime[i - 1][0] < mytime[i][0] && mytime[i][0] < record.top() && mytime[i - 1][0] < record.top())
					continue;	//1 2 3
				else if (mytime[i - 1][0] < mytime[i][0] && mytime[i][0] >= record.top() && mytime[i - 1][0] < record.top())
					record.push(mytime[i][0]);	//1 3 2
				else if (mytime[i - 1][0] < mytime[i][0] && mytime[i][0] < record.top() && mytime[i - 1][0] >= record.top())
					continue;	//impossible
				else if (mytime[i - 1][0] < mytime[i][0] && mytime[i][0] >= record.top() && mytime[i - 1][0] >= record.top())
					continue;	//2 3 1
				else if (mytime[i - 1][0] >= mytime[i][0] && mytime[i][0] < record.top() && mytime[i - 1][0] < record.top())
					record.push(mytime[i][0]);	//2 1 3
				else if (mytime[i - 1][0] >= mytime[i][0] && mytime[i][0] >= record.top() && mytime[i - 1][0] < record.top())
					continue;	//impossible
				else if (mytime[i - 1][0] >= mytime[i][0] && mytime[i][0] < record.top() && mytime[i - 1][0] >= record.top())
					continue;	//3 1 2
				else if (mytime[i - 1][0] >= mytime[i][0] && mytime[i][0] >= record.top() && mytime[i - 1][0] >= record.top())
					record.push(mytime[i][0]);	//3 2 1
			}
		}
		cout << record.size() << endl;
	}
	//fout.close();
	//system("pause");
	return 0;
}
