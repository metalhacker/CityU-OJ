#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	cin.ignore(1);
	while (t > 0)
	{
		t--;
		string input;
		getline(cin, input);
		stringstream ss;
		ss.str(input);
		string sub;
		//string res;
		while (ss >> sub)
		{
			std::transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
			if (sub.length() < 3)
				continue;
			else if (sub.compare("and") == 0 || sub.compare("for") == 0 || sub.compare("the") == 0)
				continue;
			else
				cout << (char)toupper(sub[0]);
		}
		cout << endl;
	}
	return 0;
}
