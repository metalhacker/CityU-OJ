#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void reverse(char *s, int n) {
	for (int i = 0, j = n - 1; i<j; i++, j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main()
{
	char equation[40];
	while (cin.getline(equation, 40))
	{
		if (strcmp(equation, "0+0=0") == 0)
		{
			cout << "True" << endl;
			break;
		}
		else
		{
			char stra[8];
			char strb[8];
			char strc[8];
			int i = 0;
			while (equation[i] != '+')
			{
				stra[i] = equation[i];
				i++;
			}
			stra[i] = '\0';
			i++;
			int j = 0;
			while (equation[i] != '=')
			{
				strb[j] = equation[i];
				i++; j++;
			}
			strb[j] = '\0';
			i++;
			j = 0;
			while (equation[i] != '\0')
			{
				strc[j] = equation[i];
				i++; j++;
			}
			strc[j] = '\0';
			reverse(stra, strlen(stra));
			reverse(strb, strlen(strb));
			reverse(strc, strlen(strc));
			int a = atoi(stra);
			int b = atoi(strb);
			int c = atoi(strc);
			if ((a + b) == c)
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
	}
	return 0;
}
