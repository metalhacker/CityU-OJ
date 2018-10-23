//This problem is wrong, it is impossible to reduce the memory to less than 1024kb in our OJ system
//Do not waste your time on it
//这题是错的，别做啦

#include<cstdio>
using namespace std;

char encry[200];

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++)
	{
		scanf("%s",encry);
		int j = 0;
		while (encry[j] != '\0')
		{
			if (encry[j + 2] >= '0'&&encry[j + 2] <= '9'&&encry[j + 2]!='\0')
			{
				if (encry[j + 3] >= '0'&&encry[j + 3] <= '9'&&encry[j + 3] != '\0')
				{
					for (char k = '0'; k < encry[j + 1]; k++)
					{
						for (int m = 0; m < 100; m++)
						{
							printf("%c", encry[j]);
						}
					}
					for (char k = '0'; k < encry[j + 2]; k++)
					{
						for (int m = 0; m < 10; m++)
						{
							printf("%c", encry[j]);
						}
					}
					for (char k = '0'; k < encry[j + 3]; k++)
					{				
						printf("%c", encry[j]);		
					}
					j += 4;
				}
				else
				{
					for (char k = '0'; k < encry[j + 1]; k++)
					{
						for (int m = 0; m < 10; m++)
						{
							printf("%c", encry[j]);
						}
					}
					for (char k = '0'; k < encry[j + 2]; k++)
					{
						printf("%c", encry[j]);
					}
					j += 3;
				}
			}
			else
			{
				for (char k = '0'; k < encry[j + 1]; k++)
				{
					printf("%c", encry[j]);
				}
				j += 2;
			}
		}
		printf("\n");
		//delete[]encry;
	}
	return 0;
}
