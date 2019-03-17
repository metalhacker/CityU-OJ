#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
typedef unsigned long long ull;
using namespace std;

bool prime[10000];
vector<ull>superNum;

int main()
{
	memset(prime, 0, sizeof(prime));
	for (ull i = 2; i < 100; i++)
	{
		int flag = 1;
		for (ull j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			prime[i] = 1;
		}
	}
	superNum.push_back(1);
	for (int i = 2; i < 65536; i++)
	{
		for (int j = 4; j < 64; j++)
		{
			if (prime[j])
				continue;
			if (j >(log2(UINT64_MAX) / log2(i)))
			{
				break;
			}
			ull temp = 1;
			for (int k = 0; k < j; k++)
			{
				temp *= i;
			}
			
			superNum.push_back(temp);
		}
	}
	sort(superNum.begin(), superNum.end());
	superNum.erase(unique(superNum.begin(), superNum.end()), superNum.end());
	for (int i = 1; i < superNum.size(); i++)
	{
		printf("%llu\n", superNum[i]);
	}
	return 0;
}
