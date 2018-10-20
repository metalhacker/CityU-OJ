#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	int a, b;
	char equation[1005];
	while (cin.getline(equation, 1005))
	{
		stack<int> result;
		for (int i = 0; i < strlen(equation); i++)
		{
			if (isdigit(equation[i]))
				result.push(equation[i] - 48);
			else if (equation[i] == '+')
			{
				a = result.top();
				result.pop();
				b = result.top();
				result.pop();
				result.push(a + b);
			}
			else if (equation[i] == '-')
			{
				a = result.top();
				result.pop();
				b = result.top();
				result.pop();
				result.push(b - a);
			}
			else if (equation[i] == '*')
			{
				a = result.top();
				result.pop();
				b = result.top();
				result.pop();
				result.push(a * b);
			}
		}
		cout << result.top() << endl;
	}
	return 0;
}
