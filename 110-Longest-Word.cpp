#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char word[105];
char res[105];
int main()
{
	int maximum = 0;
	while (cin >> word)
	{
		int count = 0;
		if (strcmp(word, "E-N-D") == 0)
			break;
		else
		{
			for (int i = 0; i < strlen(word); i++)
			{
				if (isalpha(word[i])||word[i]=='-')
				{
					count++;
				}
			}
			if (count > maximum)
			{
				maximum = count;
				int j = 0;
				for (int i = 0; i < strlen(word); i++)
				{
					if (isalpha(word[i]) || word[i] == '-')
					{
						res[j] = word[i];
						j++;
					}
				}
			}
		}
	}
	for (int i = 0; i < strlen(res); i++)
	{
		res[i] = tolower(res[i]);
	}
	cout << res << endl;
	return 0;
}
