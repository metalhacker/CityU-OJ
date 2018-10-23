#include<iostream>
#include<math.h>
using namespace std;
# define pi 3.14159265358979323846
int main()
{
	double r, w, l;
	int i = 0;
	bool fits;
	while (cin >> r)
	{
		i++;
		if (r == 0)
			break;
		else
		{
			cin >> w >> l;
			r *= 2;
			w = sqrt(pow(w, 2) + pow(l, 2));
			fits = w <= r ? true : false;
		}
		if (fits)
			cout << "Pizza " << i << " fits on the table." << endl;
		else
			cout << "Pizza " << i << " does not fit on the table." << endl;
	}
	return 0;
}
