#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <cstdlib>
#include <cctype>
#include <stack>
#define INF 99999
using namespace std;

int map1[205][205];
int map2[205][205];
int d1[205];
int d2[205];
int parent[205];
int visited[205];

class Vertex
{
public:
	int point;
	int distance;
	Vertex(int p, int d)
	{
		point = p;
		distance = d;
	}
	bool operator < (const Vertex &another) const
	{
		return distance > another.distance;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 205; i++)
		{
			d1[i] = INF;
			d2[i] = INF;
			for (int j = 0; j < 205; j++)
			{
				map1[i][j] = INF;
				map2[i][j] = INF;
			}
			map1[i][i] = 0;
			map2[i][i] = 0;
		}
		vector<string> places;
		string str;
		cin.ignore(1);
		for (int i = 0; i < n; i++)
		{
			getline(cin, str);
			places.push_back(str);
		}
		int p;
		cin >> p;
		string p1, p2;
		int index1, index2, distance1, distance2, istwo;
		cin.ignore(1);
		for (int i = 0; i < p; i++)
		{
			istwo = 0;
			getline(cin, str);
			
			//TODO： Get value
			int temp;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ':')
				{
					temp = i + 1;
					p1 = str.substr(0, i);
					break;
				}
			}

			for (int i = 0; i < places.size(); i++)
			{
				if (places[i] == str.substr(temp, places[i].size()))
				{
					p2 = places[i];
				}
			}
			string helper;
			for (int i = p1.length() + p2.length() + 2; i < str.length(); i++)
			{
				helper.push_back(str[i]);
			}
			if (helper.find(" ") != string::npos)
			{
				istwo = 1;
				stringstream helperstream(helper);
				helperstream >> distance1 >> distance2;
			}
			else
			{
				distance1 = stoi(helper);
			}
			index1 = std::distance(places.begin(), find(places.begin(), places.end(), p1));
			index2 = std::distance(places.begin(), find(places.begin(), places.end(), p2));
			map1[index1][index2] = distance1;
			map2[index1][index2] = distance1;
			if (istwo)
			{
				map1[index2][index1] = distance2;
				map2[index2][index1] = distance2;
			}
		}
		index1 = std::distance(places.begin(), find(places.begin(), places.end(), "office"));
		index2 = std::distance(places.begin(), find(places.begin(), places.end(), "hall"));
		d1[index1] = 0;
		d2[index2] = 0;
		memset(visited, 0, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		priority_queue<Vertex> pq;
		pq.push({ index1,0 });
		while (!pq.empty())
		{
			Vertex vertex = pq.top();
			pq.pop();
			int tnode = vertex.point, tdis = vertex.distance;
			for (int i = 0; i < n; i++)
			{
				if (d1[i] > tdis + map1[tnode][i])
				{
					d1[i] = tdis + map1[tnode][i];
					parent[i] = tnode;
					pq.push({ i, d1[i] });
				}
			}
		}
		stack<int> sp;
		string path = "";
		int tp = index2;
		while (tp != -1)
		{
			sp.push(tp);
			tp = parent[tp];
		}
		while (!sp.empty())
		{
			path += places[sp.top()];
			path += " -> ";
			sp.pop();
		}
		memset(visited, 0, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		pq.push({ index2,0 });
		while (!pq.empty())
		{
			Vertex vertex = pq.top();
			pq.pop();
			int tnode = vertex.point, tdis = vertex.distance;
			for (int i = 0; i < n; i++)
			{
				if (d2[i] > tdis + map1[tnode][i])
				{
					d2[i] = tdis + map1[tnode][i];
					parent[i] = tnode;
					pq.push({ i, d2[i] });
				}
			}
		}
		tp = index1;
		while (tp != -1)
		{
			sp.push(tp);
			tp = parent[tp];
		}
		while (!sp.empty())
		{
			if (places[sp.top()] == "hall") 
			{
				sp.pop();
				continue;
			}
			path += places[sp.top()];
			if (places[sp.top()] != "office")
				path += " -> ";
			sp.pop();
		}
		cout << (d1[index2] + d2[index1]) << endl << path << endl << endl;
	}
	return 0;
}
