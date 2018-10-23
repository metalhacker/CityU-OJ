#include <iostream>
using namespace std;

long long mypow(long long a, long long b)
{
	long long res = 1;
	for (long long i = 0; i < b; i++)
	{
		res *= a;
	}
	return res;
}

int main()
{
	long long n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else
		{
			long long marble[50];
			for (long long i = 0; i < n; i++)
			{
				cin >> marble[i];
			}
			long long sum = 0;
			for (long long i = 0; i < n; i++)
			{
				sum += marble[i] * mypow(2, i);
			}
			cout << sum << endl;
		}
	}
	return 0;
}
