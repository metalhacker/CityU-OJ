#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<string.h>
#include<algorithm>
using namespace std;
int pos[100005];
int n, c;

bool check(int mid)
{
	int pre, post;
	pre = 0;
	for (int i = 1; i < c; i++)
	{
		post = pre + 1;
		while (post<n && pos[post] - pos[pre]<mid)
			post++;
		if (post >= n)
			return false;
		pre = post;
	}
	return true;
}

int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		cases--;
		cin >> n >> c;
		for (int i = 0; i < n; i++)
			cin >> pos[i];
		sort(pos, pos + n);
		int left = pos[0];
		int right = pos[n-1];
		int mid;
		while (right > left + 1)
		{
			mid = (left + right) / 2;
			if (check(mid))
				left = mid;
			else
				right = mid;
		}
		cout << left << endl;
	}
	return 0;
}
