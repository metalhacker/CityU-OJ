#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int prime[85000];

bool isprime(int i)
{
	for (int j = 2; j <= sqrt(i); j++) {
		if (i%j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int a, b, k1, k2;
	int m = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (isprime(i))
			prime[m++] = i;
	}
	while (cin >> a >> b)
	{
		k1 = 0;
		k2 = 0;
		if (!a && !b)
			break;
		vector<int>ap;
		vector<int>bp;
		m = 0;
		while (a != 1)
		{
			if (a%prime[m] == 0 && (ap.empty() || find(ap.begin(), ap.end(), prime[m]) == ap.end()))
			{
				ap.push_back(prime[m]);
				a /= prime[m];
			}
			else if (a%prime[m] == 0)
			{
				a /= prime[m];
			}
			else
			{
				m++;
			}
		}
		m = 0;
		while (b != 1)
		{
			if (b%prime[m] == 0 && (bp.empty() || find(bp.begin(), bp.end(), prime[m]) == bp.end()))
			{
				bp.push_back(prime[m]);
				b /= prime[m];
			}
			else if (b%prime[m] == 0)
			{
				b /= prime[m];
			}
			else
			{
				m++;
			}
		}
		k1 += ap.back();
		ap.pop_back();
		while (!ap.empty())
		{
			k1 -= ap.back();
			ap.pop_back();
		}
		k2 += bp.back();
		bp.pop_back();
		while (!bp.empty())
		{
			k2 -= bp.back();
			bp.pop_back();
		}
		if (k1 > k2)
			cout << "a" << endl;
		else
			cout << "b" << endl;
	}
	return 0;
}
