#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	char str[8];
	while (~scanf("%d",&n))
	{
		long long result = 0L;
		fgets(str, 9, stdin);
		for (int i = 1; i < 2 * n; i++)
		{
			fgets(str, 9, stdin);
			result = result ^ *(long long*)str;
		}
		while (result)
		{
			printf("%c",(char)(result % (long long)(256)));
			result >>= 8;
		}
	}
	return 0;
}
