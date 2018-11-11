//Since I only now how to create a Huffman tree in O(n^2), it always shows a TLE since that n can be as large as 100000
//Therefore, we are actually not creating a Huffman tree, but using a priority queue to store the weighted length of each node
//For a Huffman tree, we have a property that
//the weighted length of all nodes is
//(w1+w2)+((w1+w2)+w3)+(((w1+w2)+w3)+w4)+......
//Then the question comes to be easy

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int n;
	priority_queue<int, vector<int>, greater<int> > pq;
	while (cin >> n) 
	{
		int sum = 0;
		int temp;
		while (!pq.empty()) 
			pq.pop();
		for (int i = 0; i<n; i++) 
		{
			cin >> temp;
			pq.push(temp);
		}
		while (pq.size() > 1) 
		{
			int c1 = pq.top();
			pq.pop();
			int c2 = pq.top();
			pq.pop();
			sum += c1 + c2;
			pq.push(c1 + c2);
      //Push it into the PQ. Since its a PQ, elements are automatically sorted
		}
		cout << sum << endl;
	}

	return 0;
}
