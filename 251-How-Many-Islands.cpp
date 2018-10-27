//Japan Local 2009
#include<iostream>
using namespace std;

class block
{
public:
	int land;
	int counted;
	block()
	{
		land = 0;
		counted = 0;
	}
};

bool check(block map[52][52],int r, int c)
{
	if (map[r][c].land == 1 && map[r][c].counted == 0)
	{
		map[r][c].counted = 1;
		for (int i = r - 1; i <= r + 1; i++)
			for (int j = c - 1; j <= c + 1; j++)
				if (map[i][j].land == 1 & map[i][j].counted == 0)
					check(map, i, j);
		return true;
	}
	else
		return false;
}

int main()
{
	int w, h;
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			break;
		block map[52][52];
		int count = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> map[i][j].land;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if (check(map,i, j))
					count++;
		cout << count << endl;
	}
	return 0;
}
