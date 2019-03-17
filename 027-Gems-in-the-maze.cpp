#include<iostream>
#include<string.h>
using namespace std;

int maze[305];
int cnt;
int a, b, c, n;
void DFS(int r)
{
	if (maze[r] == 1)
		return;
	else
	{
		cnt++;
		maze[r] = 1;
		DFS((a * r * r + b * r + c) % n);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;
		int res = 0;
		cin >> a >> b >> c >> n;
		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			memset(maze, 0, sizeof(maze));
			DFS(i);
			res = res > cnt ? res : cnt;
		}
		cout << res << endl;
	}
	return 0;
}
