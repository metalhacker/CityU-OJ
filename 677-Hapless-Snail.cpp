#include <iostream>
using namespace std;

int main()
{
	double h, u, d, f, s;
	while (cin >> h >> u >> d >> f)
	{
		int day = 0;
		s = u;
		bool flag = 1;
		double sum = 0.0;
		while (true)
		{
			day++;
			if (s - d < 0)
			{
				flag = 0;
				break;
			}
			sum += s;
			if (sum >= h)
			{
				break;
			}
			sum -= d;
			s *= (f / 100.0);
		}
		if (flag)
		{
			cout << "succeeded on day " << day << endl;
		}
		else
		{
			cout << "failed on day " << day + 1 << endl;
		}
	}
	system("pause");
	return 0;
}
