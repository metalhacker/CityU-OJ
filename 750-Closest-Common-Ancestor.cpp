#include<iostream>
using namespace std;

class member
{
public:
	int num;
	member* ancestor;
	member(int n)
	{
		num = n;
		ancestor = NULL;
	}
};

member* family[105];
int a1[105];
int a2[105];

member* getByNum(int n)
{
	int i = 0;
	while (family[i]->num != n)
		i++;
	return family[i];
}

void get1(member* m)
{
	int i = 0;
	member* temp = m;
	while (temp != NULL)
	{
		a1[i] = temp->num;
		temp = temp->ancestor;
		i++;
	}
}

void get2(member* m)
{
	int i = 0;
	member* temp = m;
	while (temp != NULL)
	{
		a2[i] = temp->num;
		temp = temp->ancestor;
		i++;
	}
}

int main()
{
	int cases;
	cin >> cases;
	int first, n;
	while (cases > 0)
	{
		cases--;
		cin >> first >> n;
		family[0] = new member(first);
		int x, a;
		for (int i = 1; i < n; i++)
		{
			cin >> x >> a;
			family[i] = new member(x);
			for (int j = 0; j < n; j++)
			{
				if (a == family[j]->num)
				{
					family[i]->ancestor = family[j];
					break;
				}
			}
		}
		for (int i = 0; i < 105; i++)
		{
			a1[i] = 0;
			a2[i] = 0;
		}
		cin >> x >> a;
		get1(getByNum(x));
		get2(getByNum(a));
		bool found = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a1[i] == a2[j])
				{
					found = 1;
					cout << a2[j] << endl;
					break;
				}
			}
			if (found)
				break;
		}
	}
	return 0;
}
