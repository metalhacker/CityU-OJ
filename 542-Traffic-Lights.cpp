#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> timett;

void process()
{
	if (timett.empty())
		return;
	int flag;
	sort(timett.begin(), timett.end());
	int clock = 2 * timett[0];
	for (int i = clock; i <= 18000; i++)
	{
		flag = 1;
		for (int j = 0; j < timett.size(); j++)
		{
			if ((i / timett[j]) % 2 != 0)
			{
				flag = 0;
				break;
			}
			else if (timett[j] - (i%timett[j]) <= 5)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			clock = i;
			break;
		}
	}
	int second, minute, hour;
	second = clock % 60;
	minute = (clock / 60) % 60;
	hour = clock / 3600;
	if (flag)
	{
		printf("%02d:%02d:%02d\n", hour, minute, second);
	}
	else
	{
		printf("Signals fail to synchronise in 5 hours\n");
	}
}

int main()
{
	int temp;
	string str;
	while (getline(cin, str))
	{
		stringstream ss(str);
		while (ss >> temp)
		{
			if (temp != 0)
				timett.push_back(temp);
			if (temp == 0)
			{
				process();
				timett.clear();
			}
		}
	}
	//system("pause");
	return 0;
}
