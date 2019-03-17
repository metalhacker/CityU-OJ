#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore(1);
	string line;
	string temp;
	stack<string>ss;
	for (int i = 1; i <= n; i++)
	{
		getline(cin, line);
		stringstream ssin(line);
		while (ssin >> temp)
			ss.push(temp);
		int isfirst = 1;
		while (!ss.empty())
		{
			if (isfirst)
			{
				cout << "Case #" << i << ": " << ss.top();
				ss.pop();
				isfirst = 0;
			}
			else
			{
				cout << " " << ss.top();
				ss.pop();
			}
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}
