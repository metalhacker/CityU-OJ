#include<iostream>
#include<string>
using namespace std;
char part[25];
int main()
{
	int cases;
	cin >> cases;
	bool first = 1;
	while (cases > 0)
	{
		string str;
		cases--;
		cin.getline(part,5);
		int parts;
		cin >> parts;
		cin.ignore(1);
		for (int i = 0; i < parts; i++)
		{
			cin.getline(part, 25);
			if (i==0)
			{
				str.append(part);
			}
			else
			{
				str.append(" ");
				str.append(part);
			}
		}
			cout << str << endl <<endl;
	}
	return 0;
}
