#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[1000];
	while (cin.getline(str, 1000))
	{
		int start = 0, end;
		for (int i = 0; i <= strlen(str); i++)
		{
			if (str[i] == ' ' || str[i] == '\0')
			{
				for (int j = start; j < (start + i) / 2; j++)
				{
					char temp = str[j];
					str[j] = str[i - 1 - j+start];
					str[i - 1 - j+start] = temp;
				}
				start = i + 1;
			}
		}
		cout << str << endl;
	}
	return 0;
}
