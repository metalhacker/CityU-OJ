#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

int main()
{
	long long a, b, res;
	char str[1000], sa[1000], sb[1000];
	while (cin.getline(str, 1000))
	{
		int i = 0;
		int j = 0;
		char op = 't';
		while (true)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				op = str[i];
				i++;
				continue;
			}
			if (op == 't')
			{
				while (str[i] != ' ')
				{
					sa[j] = str[i];
					j++; i++;
				}
				i++;
				sa[j] = '\0';
			}
			else
			{
				j = 0; i++;
				while (str[i] != '\0')
				{
					sb[j] = str[i];
					j++; i++;
				}
				i++;
				sb[j] = '\0';
				break;
			}
		}
		a = atoll(sa);
		b = atoll(sb);
		res = op == '+' ? (a + b) : (a - b);
		cout << res << endl;
	}
	return 0;
}
