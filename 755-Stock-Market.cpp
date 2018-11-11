#include<iostream>
#include<stack>
using namespace std;
int stock[100005];
int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{	
		cases--;
		int n,tp;
		long long max = 0;
		long long temp = 0;
		int size = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> stock[i];
		}
		stack<int>s;
		int i = 0;
		while(i < n)
		{
			if (s.empty() || stock[s.top()] <= stock[i])
			{
				s.push(i);
				i++;
			}
			else
			{
				tp = s.top();
				s.pop();
				temp = (long long)stock[tp] * (s.empty() ? i : i - s.top() - 1);
				max = max < temp ? temp : max;
			}
		}
		while (!s.empty())
		{
			tp = s.top();
			s.pop();
			temp = (long long)stock[tp] * (s.empty() ? i : i - s.top() - 1);
			max = max < temp ? temp : max;
		}
		cout << max << endl;
	}
	return 0;
}
