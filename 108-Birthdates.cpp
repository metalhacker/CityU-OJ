#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	string* names = new string[cases];
	int* dd = new int[cases];
	int* mm = new int[cases];
	int* yyyy = new int[cases];
	int* num = new int[cases];
	for (int i = 0; i < cases; i++)
	{
		cin >> names[i] >> dd[i] >> mm[i] >> yyyy[i];
		num[i] = yyyy[i] * 10000 + mm[i] * 100 + dd[i];
	}
	string maxN=names[0], minN=names[0];
	int maxNum, minNum;
	maxNum = num[0];
	minNum = num[0];
	for (int i = 0; i < cases; i++)
	{
		if (num[i] > maxNum)
		{
			maxNum = num[i];
			minN = names[i];
		}
		if (num[i] < minNum)
		{
			minNum = num[i];
			maxN = names[i];
		}
	}
	cout << minN << endl << maxN << endl;
	//system("pause");
	return 0;
}
