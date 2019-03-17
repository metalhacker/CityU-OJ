#include <iostream>
#include <bitset>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

bitset<8> accu = 0;
bitset<5> pc = 0;
bitset<8> mem[50] = {0};
bool flag;

int mypow(int a, int b)
{
	if (b == 0)
		return 1;
	else return a * mypow(a, b - 1);
}

int getByte(string cmd)
{
	int temp = 0;
	for (int i = 3; i < 8; i++)
		temp += (cmd.at(i) - 48)*mypow(2, 7 - i);
	return temp;
}

void terminated()
{
	cout << accu << endl;
	accu = 0;
	pc = 0;
	memset(mem, 0, 50 * sizeof(int));
	flag = 0;
}

void execute(int i)
{
	pc = bitset<5>(int(pc.to_ulong()) + 1);
	if (mem[i].to_string().substr(0, 3) == "000")
		mem[getByte(mem[i].to_string())] = accu;
	else if (mem[i].to_string().substr(0, 3) == "001")
		accu = mem[getByte(mem[i].to_string())];
	else if (mem[i].to_string().substr(0, 3) == "010" && accu == 0)
		pc = bitset<5>(getByte(mem[i].to_string()));
	else if (mem[i].to_string().substr(0, 3) == "011")
		return;
	else if (mem[i].to_string().substr(0, 3) == "100")
		accu = bitset<8>(int(accu.to_ulong()) - 1);
	else if (mem[i].to_string().substr(0, 3) == "101")
		accu = bitset<8>(int(accu.to_ulong()) + 1);
	else if (mem[i].to_string().substr(0, 3) == "110")
		pc = bitset<5>(getByte(mem[i].to_string()));
	else if (mem[i].to_string().substr(0, 3) == "111")
		terminated();
}

int main()
{
	while (cin >> mem[0])
	{
		flag = 1;
		for (int i = 1; i < 32; i++)
			cin >> mem[i];
		while (flag)
			execute(int(pc.to_ulong()));
	}
	return 0;
}
