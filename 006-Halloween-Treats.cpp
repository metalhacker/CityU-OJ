#include <stdio.h>
#include <string.h>
using namespace std;


int main()
{
	int c, n, remainder;
	int a[100000];
	int index[100000];
	while (scanf("%d%d", &c, &n))
	{
		if (c == 0 && n == 0)
			break;
		else
		{
			bool isFound = 0;
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &a[i]);
			}
			for (int i = 0; i < 100000; i++)
			{
				index[i] = -1;
			}
			index[0] = 0;
			remainder = 0;
			for (int i = 0; i < n; i++)
			{
				remainder = (remainder + a[i]) % c;
				if (index[remainder] != -1)
				{
					printf("%d", index[remainder] + 1);
					for (int j = index[remainder] + 2; j <= i + 1; j++)
					{
						printf(" %d", j);
					}
					printf("\n");
					break;
				}
				else
				{
					index[remainder] = i + 1;
				}
			}
		}
	}
	return 0;
}
