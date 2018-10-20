#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<string.h>
#include<algorithm>
using namespace std;
int pos[100005];
int n, c;

bool check(int mid)
{
	int pre, post;
	pre = 0;
	for (int i = 1; i < c; i++)	//检查是否所有元素都能被安排到间隔大于mid的房间里
	{
		post = pre + 1;
		while (post<n && pos[post] - pos[pre]<mid)	//一直移动到下一个房间，直到两个人的间隔大于mid
			post++;
		if (post >= n)		//如果移动过了最后一个房间，说明没能安排进所有人，return false
			return false;
		pre = post;	//当前这个人已经安排上了，下一个人从这个人的下一间房开始安排
	}
	return true;		//没有return false，说明所有人都安排上啦(^_^), return true即可
}

int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		cases--;
		cin >> n >> c;
		for (int i = 0; i < n; i++)
			cin >> pos[i];
		sort(pos, pos + n);	//排序，位置从小到大
		int left = pos[0];	//从第一个元素的位置开始
		int right = pos[n-1];	//以最后一个元素的位置为初始结束点
		int mid;	//记录中间值
		while (right > left + 1)
		{
			mid = (left + right) / 2;	//mid的值为left和right的中位数
			if (check(mid))		//如果check(mid) == true, 也就是说当前mid值可以塞下所有元素，所以说mid值太小了
				left = mid;	//If check(mid) == true, which means that all elements can be allocated, therefor, mid is too small. So we update the value of left to make mid larger.
			else		//如果check(mid) == false, 也就是说当前mid值不能塞下所有元素，所以说mid
				right = mid;	//If check(mid) == false, which means that some elements can't be allocate, therefore, mid is too large. So we update the value of right to make mid smaller
		}
		cout << left << endl;
	}
	return 0;
}
