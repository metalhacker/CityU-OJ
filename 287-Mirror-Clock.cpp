//UVa 11650

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	cin.ignore(1);
	while (cases > 0)
	{
		cases--;
		char time[10];
		cin.getline(time, 10);
		int i1, i2, i3, i4;
		i1 = time[0] - 48;
		i2 = time[1] - 48;
		i3 = time[3] - 48;
		i4 = time[4] - 48;
		int t1 = i1 * 10 + i2;
		int t2 = i3 * 10 + i4;
		if (t2 == 0)
			t1 = 12 - t1;
		else
			t1 = 11 - t1;
		if (t1 == -1)
			t1 = 11;
		else if (t1 == 0)
			t1 = 12;
		t2 = 60 - t2;
		if (t2 == 60)
			t2 = 0;
		i2 = t1 % 10;
		i1 = t1 / 10;
		i4 = t2 % 10;
		i3 = t2 / 10;
		time[0] = i1 + 48;
		time[1] = i2 + 48;
		time[3] = i3 + 48;
		time[4] = i4 + 48;
		cout << time << endl;
	}
	return 0;
}
