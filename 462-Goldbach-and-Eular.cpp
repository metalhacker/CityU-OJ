#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

int prime[100005];
bool isPrime[50000055];

int main()
{
	memset(isPrime, 1, sizeof(isPrime));
	int count = 0;
	for (int i = 3; i <= 100000005; i += 2)
	{
		if (isPrime[i / 2])
		{
			if (count < 100000)
			{
				count++;
				prime[count] = i;
			}
		}
		for (int j = 1; j <= count && i * prime[j] <= 100000005; j++)
		{
			isPrime[i * prime[j] / 2] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n < 4)
		{
			printf("%d is not the sum of two primes!\n", n);
		}
		else
		{
			if (n % 2 == 1)
			{
				if (isPrime[(n - 2) / 2])
				{
					printf("%d is the sum of %d and %d.\n", n, 2, n - 2);
				}
				else
				{
					printf("%d is not the sum of two primes!\n", n);
				}
			}
			else
			{
				bool flag = 0;
				for (int i = (n / 2) % 2 == 0 ? n / 2 - 1 : n / 2; i >= 3; i -= 2)
				{
					if (isPrime[i / 2] && isPrime[(n - i) / 2] && n - i - i > 0)
					{
						flag = 1;
						printf("%d is the sum of %d and %d.\n", n, i, n - i);
						break;
					}
				}
				if (!flag)
				{
					printf("%d is not the sum of two primes!\n", n);
				}
			}
		}
	}
	//system("pause");
	return 0;
}
