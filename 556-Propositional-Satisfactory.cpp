#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

int getPriority(char t)
{
	if (t == '+')	return 1;
	else if (t == '&')	return 2;
	else if (t == '!') return 3;
	else return 0;
}

int getvalue(char c)
{
	return 1;
}

int main()
{
	stack<char>temp;
	queue<char>result;
	stack<int>help;
	char a[200];
	temp.push('#');
	while (cin.getline(a,100))
	{
		for (int i = 0; i<strlen(a); i++)
		{
			if (a[i] == ' ')
				continue;
			if (isalpha(a[i]))
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
			if (isalpha(result.front()))
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
					help.push(n1 || n2);
				}
				else if (result.front() == '&')
				{
					int n1 = help.top();
					help.pop();
					int n2 = help.top();
					help.pop();
					help.push(n1 && n2);
				}
				else if (result.front() == '!')
				{
					int n1 = help.top();
					help.push(!n1);
				}
				result.pop();
			}
		}
		if (help.top())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		help.pop();
	}
	return 0;
}
