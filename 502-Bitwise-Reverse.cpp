#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

stack<int> rev;

inline void getbin(int a)
{
	int temp;
	while (a > 0)
	{
		temp = a % 2;
		rev.push(temp);
		a /= 2;
	}
}

inline int getrev()
{
	int temp;
	int res = 0;
	int helper = 1;
	while (!rev.empty())
	{
		temp = rev.top();
		res += temp * helper;
		helper *= 2;
		rev.pop();
	}
	return res;
}

int main()
{
	int n;
	while (scanf("%d",&n))
	{
		if (n == 0)
			break;
		getbin(n);
		printf("%d\n",getrev());
	}
	//system("pause");
	return 0;
}
