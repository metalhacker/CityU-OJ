#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#define INF 233

class domino
{
public:
	int value;
	int isdown;
	domino(int v) { value = v; isdown = 0; }
	domino() { isdown = 0; }
};

vector<domino*> related[10001];
domino d[10001];
int mycount = 0;

void dfs(int v)
{
	if (d[v].isdown==0)
	{
		d[v].isdown = 1;
		mycount++;
		for (int i = 0; i < related[v].size(); i++)
		{
			dfs(related[v][i]->value);
		}
	}
}

int main()
{
	int cases, n, m, l;
	cin >> cases;
	int t1, t2;
	while (cases > 0)
	{
		mycount = 0;
		cases--;
		cin >> n >> m >> l;
		for (int i = 0; i < 10001; i++)
		{
			related[i].clear();
			d[i].value = i;
			d[i].isdown = 0;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> t1 >> t2;
			related[t1].push_back(new domino(t2));
		}
		int down;
		for (int i = 0; i < l; i++)
		{
			cin >> down;
			dfs(down);
		}
		cout << mycount << endl;
	}
	return 0;
}
