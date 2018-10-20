#include<iostream>
#include<queue>
using namespace std;

class task
{
public:
	int arrival;
	int proccess;
	int id;
	task(int a, int p, int i)
	{
		arrival = a;
		proccess = p;
		id = i;
	}
};

int main()
{
	int cases;
	int a, p, pi;
	while(cin>>cases)
	{
		queue<task> q0;
		queue<task> q1;
		int res[105] = {0};
		int time = 0;
		int time1 = 0;
		int time2 = 0;
		for (int i = 0; i < cases; i++)
		{
			cin >> a >> p >> pi;
			task temp(a, p, i);
			if (pi == 0)
				q0.push(temp);
			else
				q1.push(temp);
		}
		while (!q0.empty() && !q1.empty())
		{
			if (time >= q0.front().arrival)
			{
				time += q0.front().proccess;
				res[q0.front().id] = time;
				q0.pop(); 
				continue;
			}
			if(time<q0.front().arrival)
			{
				if (time >= q1.front().arrival)
				{
					time += q1.front().proccess;
					res[q1.front().id] = time;
					q1.pop();
					continue;
				}
				else if (q0.front().arrival <= q1.front().arrival)
				{
					time = q0.front().arrival;
					time += q0.front().proccess;
					res[q0.front().id] = time;
					q0.pop();
					continue;
				}
				else
				{
					time = q1.front().arrival;
					time += q1.front().proccess;
					res[q1.front().id] = time;
					q1.pop();
					continue;
				}
			}
		}
		if (q0.empty() && !q1.empty())
		{
			while (!q1.empty())
			{
				if (time < q1.front().arrival)
				{
					time = q1.front().arrival;
					time += q1.front().proccess;
					res[q1.front().id] = time;
					q1.pop();
					continue;
				}
				else
				{
					time += q1.front().proccess;
					res[q1.front().id] = time;
					q1.pop();
					continue;
				}
			}
		}
		else
		{
			while (!q0.empty())
			{
				if (time < q0.front().arrival)
				{
					time = q0.front().arrival;
					time += q0.front().proccess;
					res[q0.front().id] = time;
					q0.pop();
					continue;
				}
				else
				{
					time += q0.front().proccess;
					res[q0.front().id] = time;
					q0.pop();
					continue;
				}
			}
		}
		for (int i = 0; i < cases - 1; i++)
		{
			cout << res[i] << " ";
		}
		cout << res[cases - 1] << endl;
	}
	return 0;
}
