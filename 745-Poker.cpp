#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> myStack;
	stack<int> myMax;
	int t, n, m, temp;
	cin >> t;
	myMax.push(0);
	while (t > 0)
	{
		t--;
		while (!myStack.empty())
		{
			myStack.pop();
			myMax.pop();
		}
		cin >> n;
		while (n > 0)
		{
			n--;
			cin >> temp;
			myStack.push(temp);
			if (myMax.top() < temp)
				myMax.push(temp);
			else
				myMax.push(myMax.top());
		}
		cin >> m;
		char op;
		while (m > 0)
		{
			m--;
			cin >> op;
			if (op == 'm')
				cout << myMax.top() << endl;
			else if (op == 'r')
			{
				myStack.pop();
				myMax.pop();
			}
			else
			{
				cin >> temp;
				myStack.push(temp);
				if (myMax.top() < temp)
					myMax.push(temp);
				else
					myMax.push(myMax.top());
			}
		}
	}
	return 0;
}
