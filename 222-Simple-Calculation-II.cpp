#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;
char str[1000];
int main()
{
	bool first = 1;
	double cnt = 1.0;
	while (cin.getline(str, 1000))
	{
		double res = 0;
		int i = 0;
		int j = 0;
		bool decimal = 0;
		while (i <= strlen(str))
		{
			if (str[i] != ' ' && str[i] != '\0' &&str[i]!='.')
			{
				i++;
				j++;
			}
			else
			{
				if (str[i - 1] == ' ')
				{
					i++;
					continue;
				}
				if (!decimal)
				{
					for (int m = 0; m < j; m++)
					{
						res += (str[i - j + m] - 48)*pow(10.0, j - m - 1);
					}
					if (str[i] == '.')
					{
						decimal = 1;
						i++;
						j = 0;
						continue;
					}
					i++;
					j = 0;
				}
				if (decimal)
				{
					for (int m = 0; m < j; m++)
					{
						res += (str[i - j + m]-48) * pow(10.0, -1 - m);
					}
					decimal = 0;
					j = 0;
				}
			}
		}
		if (first)
			first = 0;
		else
			cout << endl;
		printf("%.4lf\n", res);
	}
	return 0;
}

//Note that it seems that this problem cannot be solved with strtod or atof. But I have seen a solution with stod using string.
//Probably there accuracy are different.
