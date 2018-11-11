#include <stdio.h>

int main()
{
	int num;
	bool first = true;
	while (scanf("%d", &num) != EOF)
	{
		if (first == false)
		{
			printf("\n");
			printf("%d", num);
			printf("\n");
		}
		else
		{
			printf("%d", num);
			printf("\n");
			first = false;
		}
	}
	return 0;
}
