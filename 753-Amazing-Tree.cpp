#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<string.h>
#include<algorithm>
using namespace std;

bool check(char str[1005],int s,int e)
{
	for (int i = s; i < e; i++)
		if (str[i] != '-')
			return false;
	return true;
}

int getweight(char str[1005], int s, int e)
{
	int res;
	if (s == e - 1)
		return 1;
	stack<char> temp;
	int m = 1;
	int weight = 1;
	temp.push(str[s]);
	while (!temp.empty())
	{
		if (str[s + m] == '(')
		{
			temp.push(str[s + m]);
			weight++;
		}
		else
			temp.pop();
		m++;
	}
	res = weight;
	m = 0;
	int ns, ne;
	while ((s + m) < e - 1)
	{
		m++;
		ns = s + m;
		temp.push(str[s + m]);
		while (!temp.empty())
		{
			m++;
			if (str[s + m] == '(')
				temp.push(str[s + m]);
			else
				temp.pop();
		}
		ne = s + m;
		res = res ^ getweight(str, ns, ne);
	}
	return res;
}

int main()
{
	char str[1005];
	while (cin.getline(str, 1005))
	{
		cout << getweight(str, 0, strlen(str) - 1) << endl;
	}
}
