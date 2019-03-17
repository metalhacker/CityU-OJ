#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	int cases, n;
	cin >> cases;
	while (cases--)
	{
		cin >> n;
		n = n - 2 > 0 ? n - 2 : 0;
		cout << n << endl;
	}
	return 0;
}
