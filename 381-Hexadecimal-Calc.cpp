#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

int getPriority(char t)
{
	if (t == '+' || t == '-')	return 1;
	else if (t == '*' || t == '/')	return 2;
	else return 0;
}

int getvalue(char c)
{
	if (isdigit(c))
		return c - 48;
	else
		return c - 55;
}

int main()
{
	stack<char>temp;
	queue<char>result;
	stack<int>help;
	char a[200];
	temp.push('#');
	while (cin >> a)
	{
		for (int i = 0; i<strlen(a); i++)
		{
			if (isdigit(a[i]) || (a[i] >= 'A'&&a[i] <= 'F'))
				result.push(a[i]);
			else if (a[i] == '(')
				temp.push(a[i]);
			else if (a[i] != ')')
			{
				while (!(temp.top() == '#') && getPriority(a[i]) <= getPriority(temp.top()))
				{
					result.push(temp.top());
					temp.pop();
				}
				temp.push(a[i]);
			}
			else
			{
				while (temp.top() != '(' && temp.top() != '#')
				{
					result.push(temp.top());
					temp.pop();
				}
				if (temp.top() == '(')
					temp.pop();
			}
		}
		while (!(temp.top() == '#'))
		{
			result.push(temp.top());
			temp.pop();
		}
		int sizeR = result.size();
		for (int i = 0; i < sizeR; i++)
		{
			if (isdigit(result.front()) || (result.front() >= 'A'&&result.front() <= 'F'))
			{
				help.push(getvalue(result.front()));
				result.pop();
			}
			else
			{
				if (result.front() == '+')
				{
					int n1 = help.top();
					help.pop();
					int n2 = help.top();
					help.pop();
					help.push(n1 + n2);
				}
				else if (result.front() == '*')
				{
					int n1 = help.top();
					help.pop();
					int n2 = help.top();
					help.pop();
					help.push(n1 * n2);
				}
				else if (result.front() == '-')
				{
					int n1 = help.top();
					help.pop();
					int n2 = help.top();
					help.pop();
					help.push(n2 - n1);
				}
				else if (result.front() == '/')
				{
					int n1 = help.top();
					help.pop();
					int n2 = help.top();
					help.pop();
					help.push(n2 / n1);
				}
				result.pop();
			}
		}
		cout << uppercase << hex << help.top() << endl;
		help.pop();
	}
	return 0;
}
