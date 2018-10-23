#include <iostream>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int *feibo = new int[num + 1];
		if (num == 0)
		{
			feibo[0] = 0;
		}
		else if (num == 1)
		{
			feibo[0] = 0;
			feibo[1] = 1;
		}
		else
		{
			feibo[0] = 0;
			feibo[1] = 1;
			for (int i = 2; i <= num; i++)
			{
				feibo[i] = (feibo[i - 2] + feibo[i - 1]) % 10;
			}
		}
		cout << feibo[num] << endl;
		delete[]feibo;
	}
	return 0;
}
