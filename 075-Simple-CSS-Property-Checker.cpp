#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore(1);
	for (int i = 1; i <= n; i++)
	{
		string input;
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '-')
			{
				input[i + 1] = toupper(input[i + 1]);
				input.replace(input.find("-"), 1, "");
			}
		}
		cout << input << endl;
	}
	return 0;
}
