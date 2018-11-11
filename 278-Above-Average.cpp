//UVa 10370

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		cases--;
		int num;
		cin >> num;
		int cnt = 0;
		double av = 0.0;
		double* students = new double[num];
		for (int i = 0; i < num; i++)
		{
			cin >> students[i];
			av += students[i];
		}
		av /= ((double)(num));
		for (int i = 0; i < num; i++)
			if (students[i] > av)
				cnt++;
		double res = (double)cnt / (double)num;
		res *= 100.0;
		cout << setprecision(3) << fixed << res << "%" << endl;
	}
}
