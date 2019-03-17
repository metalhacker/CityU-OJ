#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Item
{
public:
	int price;
	int discount;
	int diff;
	int id;
	Item(int a, int b, int c, int d)
	{
		price = a;
		discount = b;
		diff = c;
		id = d;
	}
	bool operator < (const Item& another) const
	{
		return diff > another.diff;
	}
};

int main()
{
	int n, a, b;
	vector<Item>items;
	while (cin >> n)
	{
		int total = 0;
		items.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			items.push_back({ a,b,a - b,i });
			total += a;
		}
		sort(items.begin(), items.end());
		if (total < 100)
		{
			cout << total << endl;
		}
		else
		{
			for (int i = 0; i < n / 2; i++)
				total -= items[i].diff;
			cout << total << endl;
		}
	}
	return 0;
}
