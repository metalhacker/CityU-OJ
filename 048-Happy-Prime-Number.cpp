#include <iostream>
#include<cmath>
using namespace std;
int store[1000005];
int mySquare(int a)
{
	return a * a;
}

bool myFind(int tar, int* num, int n)
{
	for (int i = 0; i < n; i++)
		if (tar == num[i])
			return true;
	return false;
}

bool isHappy(int x)
{
	int temp = 0;
	int count = 0;
	while (!myFind(x, store, count))
	{
		store[count] = x;
		temp = 0;
		while (x > 0)
		{
			temp += mySquare(x % 10);
			x /= 10;
		}
		count++;
		x = temp;
	}
	if (x == 1)
		return true;
	else
		return false;
}

bool isPrime(int x)
{
	if (x % 2 == 0&& x != 2)
		return false;
	for (int i = 3; i <= sqrt(x); i+=2)
		if (x%i == 0)
			return false;
	if (x == 2)
		return true;
	if (x == 1)
		return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		if (isPrime(i) && isHappy(i))
			cout << i << endl;
	return 0;
}
