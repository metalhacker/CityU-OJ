#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, hj, lj;
		cin >> n;
		int *h = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> h[j];
		}
		hj = 0;
		lj = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if (h[j] < h[j + 1])
			{
				hj++;
			}
			else if (h[j] > h[j + 1])
			{
				lj++;
			}
		}
		cout << "Case " << i + 1 << ": " << hj << " " << lj << endl;
		delete[]h;
	}
	return 0;
}
