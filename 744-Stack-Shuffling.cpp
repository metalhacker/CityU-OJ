#include <iostream>
#include <stack>
using namespace std;
stack<int> A;
int Abackup[6666];
stack<int> B;
stack<int> S;
bool flag;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, temp;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			Abackup[j] = temp;
		}
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			while (!B.empty())
			{
				B.pop();
			}
			while (!S.empty())
			{
				S.pop();
			}
			for (int k = 0; k < n; k++)
			{
				cin >> temp;
				S.push(temp);
				A.push(Abackup[k]);
			}
			for (int k = 0; k < n; k++)
			{
				B.push(S.top());
				S.pop();
			}
			while (1)
			{
				if (!A.empty())
				{ 
					if (!S.empty())
					{
						if (S.top() == B.top())
						{
							S.pop();
							B.pop();
							continue;
						}
					}
					S.push(A.top());
					A.pop();
					if (S.top() == B.top())
					{
						S.pop();
						B.pop();
					}
				}
				else
				{
					if (B.empty())
					{
						flag = true;
						break;
					}
					else if (S.top() == B.top())
					{
						S.pop();
						B.pop();
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
			if (flag)
				cout << "Aye" << endl;
			else
				cout << "Impossible" << endl;
		}
	}
	return 0;
}
