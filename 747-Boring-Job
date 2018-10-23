#include <iostream>
#include <queue>
#include <list>
using namespace std;

class elements {
public:
	int value;
	int index;
	elements(int v, int i)
	{
		value = v;
		index = i;
	}
};

int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		list<elements> S;
		list<elements> K;
		cases--;
		int n, k, num;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> num;
			elements temp(num, i);
			S.push_back(temp);
		}
		bool isFirst = 1;
		while (!S.empty())
		{
			for (int i = 0; i < k; i++)
			{
				if (S.empty())
					break;
				K.push_back(S.front());
				S.pop_front();
			}
			int Vmax = K.front().value;
			int Vindex;
			for (list<elements>::iterator t = K.begin(); t != K.end(); t++)
			{
				Vmax = Vmax < (*t).value ? (*t).value : Vmax;
			}
			for (list<elements>::iterator t = K.begin(); t != K.end();)
			{
				if ((*t).value == Vmax)
				{
					Vindex = (*t).index;
					t = K.erase(t);
					break;
				}
				else
				{
					t++;
				}
			}
			if (!isFirst)
				cout << ' ' << Vindex;
			else
			{
				cout << Vindex;
				isFirst = 0;
			}
			while (!K.empty())
			{
				K.front().value--;
				S.push_back(K.front());
				K.pop_front();
			}
		}
		cout << endl;
	}
	return 0;
}
