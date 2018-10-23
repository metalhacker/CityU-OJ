#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cases, index, n;
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		cin >> index >> n;
		int max = n;
		while (n != 1)
		{
			n = n % 2 == 0 ? n / 2 : 3 * n + 1;
			max = n > max ? n : max;
		}
		cout << index << " " << max << endl;
	}
	return 0;
}
