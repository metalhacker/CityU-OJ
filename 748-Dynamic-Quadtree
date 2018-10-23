#include <iostream>
using namespace std;
bool maze[1030][1030];
char flag[1030];
int mypow(int a, int b)
{
	int pow = 1;
	for (int m = 0; m < b; m++)
	{
		pow *= a;
	}
	return pow;
}

int checkMaze(int r, int c, int size, int& cnt) {
	if (size == 2)
	{
		if (maze[r][c] == maze[r][c + 1] & maze[r][c] == maze[r + 1][c] & maze[r][c] == maze[r + 1][c + 1])
			return maze[r][c];
		else
		{
			cnt += 4;
			return -1;
		}
	}
	else
	{
		int s = checkMaze(r, c, size / 2, cnt);
		if (s != -1 & s == checkMaze(r, c + size / 2, size / 2, cnt) & s == checkMaze(r + size / 2, c, size / 2, cnt) & s == checkMaze(r + size / 2, c + size / 2, size / 2, cnt))
		{
			return s;
		}
		else
		{
			cnt += 4;
			return -1;
		}
	}
}

bool checkSame(int i,int j)
{
	bool res;
	if ((i + 1) % 2 == 0)
	{
		if ((j + 1) % 2 == 0)
			res = (maze[i][j] == maze[i - 1][j - 1] && maze[i][j] == maze[i - 1][j] && maze[i][j] == maze[i][j - 1]);
		else
			res = (maze[i][j] == maze[i - 1][j] && maze[i][j] == maze[i - 1][j + 1] && maze[i][j] == maze[i][j + 1]);
	}
	else
	{
		if ((j + 1) % 2 == 0)
			res = (maze[i][j] == maze[i][j - 1] && maze[i][j] == maze[i + 1][j] && maze[i][j] == maze[i + 1][j - 1]);
		else
			res = (maze[i][j] == maze[i][j + 1] && maze[i][j] == maze[i + 1][j] && maze[i][j] == maze[i + 1][j + 1]);
	}
	return res;
}

int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		cases--;
		int k;
		int n;
		cin >> k;
		if (k == 0)
		{
			cin >> n;
			int flip;
			cin >> flip;
			while (flip > 0)
			{
				flip--;
				int r1, c1;
				cin >> r1 >> c1;
				cout << 1 << endl;
			}
		}
		else {
			n = mypow(2, k);
			for (int i = 0; i < n; i++) {
				cin >> flag;
				for (int j = 0; j < n; j++)
					maze[i][j] = flag[j] == '1' ? 1 : 0;
			}
			int num = 1;
			checkMaze(0, 0, n, num);
			int flipnum;
			cin >> flipnum;
			while (flipnum > 0)
			{
				flipnum--;
				int r, c;
				cin >> r >> c;
				if (checkSame(r - 1, c - 1))
				{
					num = 1;
					maze[r - 1][c - 1] = maze[r - 1][c - 1] == 1 ? 0 : 1;
					checkMaze(0, 0, n, num);
				}
				else
				{
					maze[r - 1][c - 1] = maze[r - 1][c - 1] == 1 ? 0 : 1;
					if (checkSame(r - 1, c - 1))
					{
						num = 1;
						checkMaze(0, 0, n, num);
					}
				}
				cout << num << endl;
			}
		}
	}
	return 0;
}

//code of my friend

#include <stdio.h>
#define child(k,n) 4*k+n 
//#define DEBUG
char arr[1024][1025];
int numTree[1398110];
int n, t, op, matsize, row, col;

void Ctt(int r, int c, int size, int id) {
	if (size == 1) {
		numTree[id] = 1;
	}
	else {
		int ns = size >> 1;
		int m1 = r + ns;
		int m2 = c + ns;
		Ctt(r, c, ns, child(id, 1));
		Ctt(r, m2, ns, child(id, 2));
		Ctt(m1, c,ns, child(id, 3));
		Ctt(m1, m2, ns, child(id, 4));
		int x1 = numTree[child(id, 1)];
		int x2 = numTree[child(id, 2)];
		int x3 = numTree[child(id, 3)];
		int x4 = numTree[child(id, 4)];
		if (x1 != 1 || x2 != 1
			|| x3 != 1 || x4 != 1
			|| arr[r][c] != arr[r][m2] || arr[r][c] != arr[m1][c] || arr[r][c] != arr[m1][m2]) {
			numTree[id] = 1 + x1 + x2 + x3 + x4;
		}
		else
			numTree[id] = 1;
	}
}



void Swim(int r, int c, int size, int id) {
	if (size == 1) {
		numTree[id] = 1;
	}
	else {
		int ns = size >> 1;
		int midr = r +ns;	//the first one of right sub
		int midc = c + ns;	//the first one of down sub
		if (row - 1 < midr) {
			if (col - 1 < midc) {
				Swim(r, c, ns, child(id, 1));
			}
			else {
				Swim(r, midc, ns, child(id, 2));
			}
		}
		else {
			if (col - 1 < midc) {
				Swim(midr, c, ns, child(id, 3));
			}
			else {
				Swim(midr, midc, ns, child(id, 4));
			}
		}
		int x1 = numTree[child(id, 1)];
		int x2 = numTree[child(id, 2)];
		int x3 = numTree[child(id, 3)];
		int x4 = numTree[child(id, 4)];
		if (x1 != 1 || x2 != 1
			|| x3 != 1 || x4 != 1
			|| arr[r][c] != arr[r][midc] || arr[r][c] != arr[midr][c] || arr[r][c] != arr[midr][midc]) {
			numTree[id] = 1 + x1 + x2 + x3 + x4;
		}
		else
			numTree[id] = 1;
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		matsize = 1 << n;
		gets(arr[0]);
		for (int i = 0; i < matsize; i++) {
			gets(arr[i]);
		}
		scanf("%d", &op);
		for (int i = 0; i < op; i++) {
			scanf("%d%d", &row, &col);
			arr[row - 1][col - 1] = (!(arr[row - 1][col - 1]-'0'))+'0';
			if (!n)
				printf("1\n");
			else {
				if (!i) {
					Ctt(0, 0, matsize, 0);
					printf("%d\n", numTree[0]);
				}
				else {
					Swim(0, 0, matsize, 0);
					printf("%d\n", numTree[0]);
				}
			}
		}
	}
	return 0;
}
