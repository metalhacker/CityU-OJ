#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		queue<int> arrival;
		queue<int> service;
		queue<int> wait;
		int a, s, w;
		int time = 0;
		int temp = 0;
		while (!arrival.empty())
			arrival.pop();
		while (!service.empty())
			service.pop();
		while (!wait.empty())
			wait.pop();
		while (n > 0)
		{
			n--;
			cin >> a >> s >> w;
			if (time < a)
				time = a;
			while (!arrival.empty())
			{
				if (temp + service.front() <= a)
				{
					temp += service.front();
					service.pop();
					arrival.pop();
					wait.pop();
				}
				else
				{
					break;
				}
			}
			if (arrival.empty())
			{
				temp = a;
			}
			if (w >= wait.size() || n == 0)
			{
				time += s;
				service.push(s);
				arrival.push(a);
				wait.push(w);
			}
			else
				continue;
		}
		if (w < wait.size() - 1)
			cout << -1 << endl;
		else
		{
			cout << time - s << endl;
		}
	}
	return 0;
}
