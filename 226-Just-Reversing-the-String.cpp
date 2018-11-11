#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char str[150];

int main()
{
	while (cin.getline(str,150))
	{
		reverse(str, str + strlen(str));
		for (int i = 0; i < strlen(str); i++)
		{
			if (isalpha(str[i]))
			{
				if (isupper(str[i]))
				{
					str[i]=tolower(str[i]);
				}
				else if(islower(str[i]))
				{
					str[i] = toupper(str[i]);
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}
