#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char input[52];
		char res[52];
		memset(input, 0, 52);
		memset(res, 0, 52);
		cin >> input;
		res[0] = input[0];
		int flagIn, flagRes;
		flagIn = 0;
		flagRes = 0;
		while (input[flagIn] != '\0')
		{
			bool isLarge = 0;
			for (int j = flagIn + 1; j < strlen(input); j++)
			{
				if (input[j] > res[flagRes])
				{
					flagIn = j;
					res[flagRes] = input[j];
					isLarge = 1;
				}
			}
			if (isLarge == 0)
			{
				flagRes++;
				flagIn++;
				res[flagRes] = input[flagIn];
			}
		}
		cout << res << endl;
	}
}
