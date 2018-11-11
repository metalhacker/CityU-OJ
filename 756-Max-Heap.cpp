#include<iostream>
using namespace std;
int heap[100005];
int s;

void add(int k)
{
	s++;
	int i = s;
	heap[s] = k;
	while (i>1 && heap[i] > heap[i / 2])
	{
		int temp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = temp;
		i = i / 2;
	}
}

void del()
{
	heap[1] = heap[s];
	heap[s] = 0;
	s--;
	int i = 1;
	while (heap[i] < heap[i * 2] || heap[i] < heap[i * 2 + 1])
	{
		if (heap[i * 2] > heap[i * 2 + 1])
		{
			if (heap[i] < heap[i * 2])
			{
				int temp = heap[i];
				heap[i] = heap[i * 2];
				heap[i * 2] = temp;
				i = i * 2;
			}
		}
		else if (heap[i] < heap[i * 2 + 1])
		{
			int temp = heap[i];
			heap[i] = heap[i * 2 + 1];
			heap[i * 2 + 1] = temp;
			i = i * 2 + 1;
		}
	}
}

void print()
{
	int sum = 0;
	for (int i = 1; i <= s; i++)
	{
		sum += heap[i];
	}
	cout << sum << endl;
}

int main()
{
	int n;
	char op;
	while (cin >> n)
	{
		for (int i = 0; i <= s; i++)
			heap[i] = 0;
		s = 0;
		while (n > 0)
		{
			n--;
			cin >> op;
			if (op == 'a')
			{
				int t;
				cin >> t;
				add(t);
			}
			else if (op == 'p')
				del();
			else if (op == 'r')
				print();
		}
	}
	return 0;
}
