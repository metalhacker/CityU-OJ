//For this question, you actually do not need to use a tree. 
//Since you only need to count out the weight of each node, the task should be deternmining where is a node and what is its weight.
//For example, a string like ((()())()), for each node, the number of left brackets is the same as its weight. 
//And to find a node, use a stack to determine the start and end index of the node in the string.

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

int getweight(char str[1005], int s, int e)	//s denotes start, e denotes end
{
	int res;
	if (s == e - 1)
		return 1;
	stack<char> temp;
	int m = 1;	//simply an iteration variable
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
	int ns, ne;	//new start, new end
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
