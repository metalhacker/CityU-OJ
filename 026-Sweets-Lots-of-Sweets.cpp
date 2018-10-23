#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;
		int r, c;
		int count = 0;
		cin >> r >> c;
		char** candy = new char*[r];
		for (int i = 0; i < r; i++)
			candy[i] = new char[c];
		cin.ignore(1);
		for (int i = 0; i < r; i++)
		{
			cin.getline(candy[i], 405);
			for (int j = 0; j < c - 2; j++)
			{
				if (candy[i][j] == '>')
					if (candy[i][j + 1] == 'o'&&candy[i][j + 2] == '<')
						count++;
			}
		}
		for (int j = 0; j < c; j++)
		{
			for (int i = 0; i < r - 2; i++)
			{
				if (candy[i][j] == 'v')
					if (candy[i + 1][j] == 'o'&&candy[i + 2][j] == '^')
						count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
