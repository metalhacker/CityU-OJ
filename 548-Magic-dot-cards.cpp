#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main()
{
	ull powers[80];
	powers[0] = 1;
	for (int i = 1; i <= 63; i++)
	{
		powers[i] = powers[i - 1] << 1;
	}
	ull n1, n2;
	while (cin >> n1 >> n2)
	{
		bitset<64> b1(n1);
		bitset<64> b2(n2);
		vector<int> flag;
		int f1 = 0, f2 = 0;
		while (b1 != 0 || b2 != 0)
		{
			f1 = 0; f2 = 0;
			for (int i = 63; i >= 0; i--)
			{
				if (b1[i] == 1)
				{
					f1 = i;
					break;
				}
			}
			for (int i = 63; i >= 0; i--)
			{
				if (b2[i] == 1)
				{
					f2 = i;
					break;
				}
			}
			if (f1 == f2)
			{
				flag.push_back(f1);
				b1[f1] = 0;
				b2[f1] = 0;
			}
			else
			{
				for (int i = 0; i <= max(f1, f2); i++)
				{
					flag.push_back(i);
				}
				break;
			}
		}
		ull res = 0;
		for (int i = 0; i < flag.size(); i++)
		{
			res += powers[flag[i]];
		}
		cout << res << endl;
	}
	//system("pause");
	return 0;
}
