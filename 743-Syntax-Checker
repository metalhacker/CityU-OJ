#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
char str[100005];


int main()
{
	while (cin.getline(str,100005))
	{
		int index = 0;
		bool found = 0;
		stack<char> brackets;
		stack<int> count;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				brackets.push(str[i]);
				count.push(i);
			}
			else if (str[i] == ')')
			{
				if (brackets.empty())
				{
					found = 1;
					index = i; 
					break;
				}
				else if (brackets.top() != '(')
				{
					found = 1;
					index = i;
					break;
				}
				else
				{
					brackets.pop();
					count.pop();
				}
			}
			else if (str[i] == ']')
			{
				if (brackets.empty())
				{
					found = 1;
					index = i;
					break;
				}
				else if (brackets.top() != '[')
				{
					found = 1;
					index = i;
					break;
				}
				else
				{
					brackets.pop();
					count.pop();
				}
			}
			else if (str[i] == '}')
			{
				if (brackets.empty())
				{
					found = 1;
					index = i;
					break;
				}
				else if (brackets.top() != '{')
				{
					found = 1;
					index = i;
					break;
				}
				else
				{
					brackets.pop();
					count.pop();
				}
			}
		}
		if (brackets.empty() && (index == 0) && (found == 0))
		{
			cout << "Success" << endl;
		}
		else if (index != 0)
		{
			cout << index + 1 << endl;
		}
		else
		{
			while (!count.empty())
			{
				index = count.top();
				count.pop();
			}
			cout << index + 1 << endl;
		}
	}
	return 0;
}
