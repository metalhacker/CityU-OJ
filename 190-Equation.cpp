#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int getPriority(char t)
{
	if (t == '+' || t == '-')	return 1;
	else if (t == '*' || t == '/')	return 2;
	else return 0;
}

int main()
{
	int cases;
	cin >> cases;
	stack<string>temp;
	queue<string>result;
	string a;
	temp.push("#");
	cin.ignore(1);
	getline(cin, a);
	for (int i = 0; i < cases; i++)
	{
		while (getline(cin, a))
		{
			if (a.empty())
				break;
			if (isdigit(a[0]))
				result.push(a);
			else if (a.compare("(") == 0)
				temp.push(a);
			else if (a.compare(")") != 0)
			{
				while (!(temp.top().compare("#") == 0) && getPriority(a[0]) <= getPriority(temp.top().at(0)))
				{
					result.push(temp.top());
					temp.pop();
				}
				temp.push(a);
			}
			else
			{
				while (temp.top().compare("(") != 0 && temp.top().compare("#") != 0)
				{
					result.push(temp.top());
					temp.pop();
				}
				if(temp.top().compare("(")==0)
					temp.pop();
			}
		}
		while (!(temp.top().compare("#") == 0))
		{
			result.push(temp.top());
			temp.pop();
		}
		while (!result.empty())
		{
			cout << result.front();
			result.pop();
		}
		if (i < cases - 1)
			cout << endl << endl;
		else cout << endl;
	}
	return 0;
}
