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
#include <climits>
#include <map>
#include <utility>
#define INF 99999999
using namespace std;

class Trap
{
public:
	int room_number;
	char trap_type;
	int trap_value;
	Trap() { room_number = 0; trap_type = 'n'; trap_value = 0; }
	Trap(int a, char b, int c)
	{
		room_number = a;
		trap_type = b;
		trap_value = c;
	}
};

class Vertex
{
public:
	int point;
	int distance;
	int rvalue;
	Vertex(int a, int b, int c)
	{
		point = a;
		distance = b;
		rvalue = c;
	}
	bool operator < (const Vertex &another) const
	{
		return distance > another.distance;
	}
};

class Edge
{
public:
	int room_number;
	int distance;
	bool operator < (const Edge &another) const
	{
		if (room_number != another.room_number)
			return room_number < another.room_number;
		return distance < another.distance;
	}
};

Trap traps[1005];
vector<Edge> G[1005];
int total_number_of_rooms, number_of_corridors, number_of_traps, room_number_of_entrance,
initial_ring_position, room_number_of_treasure_room, open_ring_position;

int ring(int r)
{
	int res = r % 12;
	if (res <= 0)
		res += 12;
	return res;
}

int calc(int id, int r)
{
	if (traps[id].trap_type == '+')
		return ring(r + traps[id].trap_value);
	else if (traps[id].trap_type == '-')
		return ring(r - traps[id].trap_value);
	else if (traps[id].trap_type == '*')
		return ring(r * traps[id].trap_value);
	else if (traps[id].trap_type == '=')
		return ring(traps[id].trap_value);
	else return ring(r);
}

int main()
{
	while (cin >> total_number_of_rooms >> number_of_corridors >> number_of_traps >> room_number_of_entrance >> initial_ring_position >> room_number_of_treasure_room >> open_ring_position)
	{
		for (int i = 0; i < 1005; i++)
		{
			traps[i] = { 0,'n',0 };
			G[i].clear();
		}
		int r1, r2, cv;
		char tempc;
		for (int i = 0; i < number_of_corridors; i++)
		{
			cin >> r1 >> r2 >> cv;
			G[r1].push_back({ r2, cv });
			G[r2].push_back({ r1, cv });
		}
		for (int i = 0; i < number_of_traps; i++)
		{
			cin >> r1 >> tempc >> cv;
			traps[r1] = { r1,tempc,cv };
		}
		bool isopen = 0;
		map<Edge, int> mmp;
		priority_queue<Vertex>pq;
		pq.push({ room_number_of_entrance,0,initial_ring_position });
		while (!pq.empty())
		{
			Vertex vertex = pq.top();
			pq.pop();
			int tnode = vertex.point, tdis = vertex.distance, tvalue = vertex.rvalue;
			int nnode, ndis, nvalue;	//next
			if (tnode == room_number_of_treasure_room && tvalue == open_ring_position)
			{
				cout << tdis << endl;
				isopen = 1;
				break;
			}
			for (int i = 0; i < G[tnode].size(); i++)
			{
				nnode = G[tnode][i].room_number;
				ndis = G[tnode][i].distance;
				nvalue = calc(nnode, tvalue);
				if (mmp.find({nnode,nvalue}) == mmp.end())
				{
					pq.push({ nnode,ndis + tdis,nvalue });
					mmp[{nnode,nvalue}] = ndis + tdis;
				}
				else if (mmp[{nnode,nvalue}] > ndis + tdis)
				{
					pq.push({ nnode, ndis + tdis, nvalue });
					mmp[G[tnode][i]] = ndis + tdis;
				}
			}
		}
		if (!isopen)
		{
			cout << "Pray!" << endl;
		}
	}
	return 0;
}
