#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	char str[10000];
	int count = 0;
	while (cin.getline(str, 10000))
	{
		count = 0;
		int isWord = 0;
		for (int i = 0; str[i]; i++)
		{
			if (isalpha(str[i]))
			{
				isWord = 1;
			}
			else
			{
				if (isWord)
					count++;
				isWord = 0;
			}
		}
		count += isWord;
		cout << count << endl;
	}
	return 0;
}
