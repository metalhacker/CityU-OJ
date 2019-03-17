#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b, c, d, t;

vector<int> mycount;
queue < vector<int> > q;
int visited[26][26][26][26];
int step[26][26][26][26];

int bfs()
{
	if ((t > a) && (t > b) && (t > c) && (t > d))
		return -1;
	mycount.clear();
	queue < vector<int> > emptyq;
	memset(visited, 0, sizeof(visited));
	swap(q, emptyq);
	q.push({ 0,0,0,0 });
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < 26; k++)
				for (int l = 0; l < 26; l++)
					step[i][j][k][l] = 999999;
	step[0][0][0][0] = 0;
	while (!q.empty())
	{
		vector<int> curr = q.front();
		//cout << curr[0] << " " << curr[1] << " " << curr[2] << " " << curr[3] << " " << step[curr[0]][curr[1]][curr[2]][curr[3]] << endl;
		q.pop();
		if (curr[0] > a || curr[1] > b || curr[2] > c || curr[3] > d || curr[0] < 0 || curr[1] < 0 || curr[2] < 0 || curr[3] < 0)
			continue;
		if (visited[curr[0]][curr[1]][curr[2]][curr[3]] == 1)
			continue;
		visited[curr[0]][curr[1]][curr[2]][curr[3]] = 1;
		if (curr[0] == t || curr[1] == t || curr[2] == t || curr[3] == t)
		{
			//cout << step[curr[0]][curr[1]][curr[2]][curr[3]] << " ";
			mycount.push_back(step[curr[0]][curr[1]][curr[2]][curr[3]]);
			break;
		}
		//fill a,b,c,d respectivelly
		if (visited[a][curr[1]][curr[2]][curr[3]] == 0)
		{
			q.push({ a,curr[1],curr[2],curr[3] });
			step[a][curr[1]][curr[2]][curr[3]] = min(step[a][curr[1]][curr[2]][curr[3]],step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		//empty a,b,c,d
		if (visited[0][curr[1]][curr[2]][curr[3]] == 0)
		{
			q.push({ 0,curr[1],curr[2],curr[3] });
			step[0][curr[1]][curr[2]][curr[3]] = min(step[0][curr[1]][curr[2]][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		//a-->b,c,d

		for (int i = 0; i < max(a, b); i++)
		{
			int t1 = curr[0] - i;
			int t2 = curr[1] + i;
			if ((t1 == 0 || t2 == b))
			{
				if (visited[t1][t2][curr[2]][curr[3]] == 0)
				{
					q.push({ t1, t2, curr[2], curr[3] });
					step[t1][t2][curr[2]][curr[3]] = min(step[t1][t2][curr[2]][curr[3]],step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(a, c); i++)
		{
			int t1 = curr[0] - i;
			int t2 = curr[2] + i;
			if ((t1 == 0 || t2 == c))
			{
				if (visited[t1][curr[1]][t2][curr[3]] == 0)
				{
					q.push({ t1, curr[1], t2, curr[3] });
					step[t1][curr[1]][t2][curr[3]] = min(step[t1][curr[1]][t2][curr[3]],step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(a, d); i++)
		{
			int t1 = curr[0] - i;
			int t2 = curr[3] + i;
			if ((t1 == 0 || t2 == d))
			{
				if (visited[t1][curr[1]][curr[2]][t2] == 0)
				{
					q.push({ t1, curr[1], curr[2], t2 });
					step[t1][curr[1]][curr[2]][t2] = min(step[t1][curr[1]][curr[2]][t2],step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}


		if (visited[curr[0]][b][curr[2]][curr[3]] == 0)
		{
			q.push({ curr[0],b,curr[2],curr[3] });
			step[curr[0]][b][curr[2]][curr[3]] = min(step[curr[0]][b][curr[2]][curr[3]],step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		if (visited[curr[0]][0][curr[2]][curr[3]] == 0)
		{
			q.push({ curr[0],0,curr[2],curr[3] });
			step[curr[0]][0][curr[2]][curr[3]] = min(step[curr[0]][0][curr[2]][curr[3]],step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		//b-->a,c,d

		for (int i = 0; i < max(a, b); i++)
		{
			int t1 = curr[1] - i;
			int t2 = curr[0] + i;
			if ((t1 == 0 || t2 == a))
			{
				if (visited[t2][t1][curr[2]][curr[3]] == 0)
				{
					q.push({ t2, t1, curr[2], curr[3] });
					step[t2][t1][curr[2]][curr[3]] = min(step[t2][t1][curr[2]][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(b, c); i++)
		{
			int t1 = curr[1] - i;
			int t2 = curr[2] + i;
			if ((t1 == 0 || t2 == c))
			{
				if (visited[curr[0]][t1][t2][curr[3]] == 0)
				{
					q.push({ curr[0], t1, t2, curr[3] });
					step[curr[0]][t1][t2][curr[3]] = min(step[curr[0]][t1][t2][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(b, d); i++)
		{
			int t1 = curr[1] - i;
			int t2 = curr[3] + i;
			if ((t1 == 0 || t2 == d))
			{
				if (visited[curr[0]][t1][curr[2]][t2] == 0)
				{
					q.push({ curr[0], t1, curr[2], t2 });
					step[curr[0]][t1][curr[2]][t2] = min(step[curr[0]][t1][curr[2]][t2], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}


		if (visited[curr[0]][curr[1]][c][curr[3]] == 0)
		{
			q.push({ curr[0],curr[1],c,curr[3] });
			step[curr[0]][curr[1]][c][curr[3]] = min(step[curr[0]][curr[1]][c][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		if (visited[curr[0]][curr[1]][0][curr[3]] == 0)
		{
			q.push({ curr[0],curr[1],0,curr[3] });
			step[curr[0]][curr[1]][0][curr[3]] = min(step[curr[0]][curr[1]][0][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		//c-->b,a,d

		for (int i = 0; i < max(a, c); i++)
		{
			int t1 = curr[2] - i;
			int t2 = curr[0] + i;
			if ((t1 == 0 || t2 == a))
			{
				if (visited[t2][curr[1]][t1][curr[3]] == 0)
				{
					q.push({ t2, curr[1], t1, curr[3] });
					step[t2][curr[1]][t1][curr[3]] = min(step[t2][curr[1]][t1][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(b, c); i++)
		{
			int t1 = curr[2] - i;
			int t2 = curr[1] + i;
			if ((t1 == 0 || t2 == b))
			{
				if (visited[curr[0]][t2][t1][curr[3]] == 0)
				{
					q.push({ curr[0], t2, t1, curr[3] });
					step[curr[0]][t2][t1][curr[3]] = min(step[curr[0]][t2][t1][curr[3]], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(c, d); i++)
		{
			int t1 = curr[2] - i;
			int t2 = curr[3] + i;
			if ((t1 == 0 || t2 == d))
			{
				if (visited[curr[0]][curr[1]][t1][t2] == 0)
				{
					q.push({ curr[0], curr[1], t1, t2 });
					step[curr[0]][curr[1]][t1][t2] = min(step[curr[0]][curr[1]][t1][t2], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}

		if (visited[curr[0]][curr[1]][curr[2]][d] == 0)
		{
			q.push({ curr[0],curr[1],curr[2],d });
			step[curr[0]][curr[1]][curr[2]][d] = min(step[curr[0]][curr[1]][curr[2]][d], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}
		
		if (visited[curr[0]][curr[1]][curr[2]][0] == 0)
		{
			q.push({ curr[0],curr[1],curr[2],0 });
			step[curr[0]][curr[1]][curr[2]][0] = min(step[curr[0]][curr[1]][curr[2]][0], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
		}

		//d-->b,c,a

		for (int i = 0; i < max(a, d); i++)
		{
			int t1 = curr[3] - i;
			int t2 = curr[0] + i;
			if ((t1 == 0 || t2 == a))
			{
				if (visited[t2][curr[1]][curr[2]][t1] == 0)
				{
					q.push({ t2, curr[1], curr[2], t1 });
					step[t2][curr[1]][curr[2]][t1] = min(step[t2][curr[1]][curr[2]][t1], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(b, d); i++)
		{
			int t1 = curr[3] - i;
			int t2 = curr[1] + i;
			if ((t1 == 0 || t2 == b))
			{
				if (visited[curr[0]][t2][curr[2]][t1] == 0)
				{
					q.push({ curr[0], t2, curr[2], t1 });
					step[curr[0]][t2][curr[2]][t1] = min(step[curr[0]][t2][curr[2]][t1], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
		for (int i = 0; i < max(c, d); i++)
		{
			int t1 = curr[3] - i;
			int t2 = curr[2] + i;
			if ((t1 == 0 || t2 == c))
			{
				if (visited[curr[0]][curr[1]][t2][t1] == 0)
				{
					q.push({ curr[0], curr[1], t2, t1 });
					step[curr[0]][curr[1]][t2][t1] = min(step[curr[0]][curr[1]][t2][t1], step[curr[0]][curr[1]][curr[2]][curr[3]] + 1);
				}
				break;
			}
		}
	}
	if (mycount.empty())
		return -1;
	else
	{
		sort(mycount.begin(), mycount.end());
		return mycount.front();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> a >> b >> c >> d >> t)
	{
		cout << bfs() << endl;
	}
	return 0;
}
