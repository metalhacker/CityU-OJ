//uva10608
#include <iostream>
#include <algorithm>
using namespace std;

int Parent[30005];
int Rank[30005];
//int size[30005];

void Init(int num)
{
	for (int i = 0; i <= num; i++)
	{
		Parent[i] = i;
		Rank[i] = 1;
	}
}

//Finding the root of target
int Find(int target)
{
	if (target != Parent[target])
		return Find(Parent[target]);
	else
		return target;
}

void Union(int a, int b)
{
	int aRoot = Find(a);
	int bRoot = Find(b);
	if (aRoot == bRoot)
		return;
	if (Rank[aRoot] > Rank[bRoot])
	{
		Rank[aRoot] += Rank[bRoot];
		Parent[bRoot] = aRoot;
	}
	else 
	{
		Rank[bRoot] += Rank[aRoot];
		Parent[aRoot] = bRoot;
	}
}

bool isConnected(int a, int b)
{
	return (Find(a) == Find(b));
}

int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int people, pairs;
		cin >> people >> pairs;
		Init(people);
		for (int j = 0; j < pairs; j++)
		{
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}
		int max = 0;
		for (int j = 1; j <= people; j++)
			if (max < Rank[j])
				max = Rank[j];
		cout << max << endl;
	}
	return 0;
}
