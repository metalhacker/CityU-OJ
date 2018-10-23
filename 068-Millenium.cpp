#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n > 0)
	{
		n--;
		int y, m, d;
		int count = 0;
		cin >> y >> m >> d;
		if (y % 3 != 0)
		{
			count -= (d - 1);
			if (m % 2 == 0)
				count -= (39 * (m / 2) - 19);
			else
				count -= (39 * (m / 2));
			if (y % 3 == 1)
				count += 590 * ((1000 - y) / 3);
			else
				count += (590 * ((1001 - y) / 3) - 195);
		}
		else
		{
			count -= (d - 1);
			count -= 20 * (m - 1);
			count += (590 * ((1000 - y) / 3) + 200);
		}
		cout << count << endl;
	}
	return 0;
}
