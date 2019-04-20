#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long int ll;

int main()
{
	ll a, k, n, result;
	while (cin >> a >> k >> n)
	{
		a %= n;
		result = 1;
		while (k)
		{
			if (k & 1)
			{
				result = result * a % n;
			}
			a = a * a % n;
			k >>= 1;
		}
		cout << result << endl;
	}
	return 0;
}
