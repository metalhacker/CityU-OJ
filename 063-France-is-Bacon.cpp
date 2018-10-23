#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string France = "France";
	string Bacon = "Bacon";
	cin.ignore(1);
	for (int i = 1; i <= n; i++)
	{
		string input;
		int count = 0;
		getline(cin, input);
		while (1)
		{
			if (input.find(France) != string::npos)
			{
				count++;
				input.replace(input.find(France), France.length(), Bacon);
			}
			else
				break;
		}
		cout << "Sentence #" << i << ": " << count << endl;
	}
	return 0;
}
