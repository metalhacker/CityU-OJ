#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

vector<string>suffix;
int sa[2000];
int srank[2000];
int height[2000];

int main()
{
	//ofstream fout("out.txt");
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		suffix.clear();
		memset(sa, 0, sizeof(sa));
		memset(srank, 0, sizeof(srank));
		memset(height, 0, sizeof(height));
		for (int i = 0; i < str.length(); i++)
		{
			suffix.push_back(str.substr(i));
		}
		sort(suffix.begin(), suffix.end());
		for (int i = 0; i < str.length(); i++)
		{
			sa[i] = str.length() - suffix[i].length();
			srank[sa[i]] = i;
		}
		int k = 0;
		char cstr[1005];
		for (int i = 0; i < str.length(); i++)
		{
			cstr[i] = str.at(i);
		}
		cstr[str.length()] = '\0';
		for (int i = 0; i < str.length(); i++) {
			if (srank[i] == 0)
				continue;
			while (cstr[i + k] == cstr[sa[srank[i] - 1] + k] && (i+k) <=str.length() && (sa[srank[i] - 1] + k)<=str.length())
			{
				k++;
			}
			height[srank[i]] = k;
			if (k > 0)
			{
				k--;
			}
		}
		int maxh = 0;
		for (int i = 0; i < str.length(); i++)
		{
			maxh < height[i] ? maxh = height[i] : maxh;
		}
		string maxs;
		for (int i = 0; i < str.length(); i++)
		{
			if (height[i] == maxh)
			{
				string temp = str.substr(sa[i], maxh);
				if (temp.length() > maxs.length())
				{
					maxs = temp;
				}
				else if (temp.length() == maxs.length() && temp < maxs)
				{
					maxs = temp;
				}
			}
		}
		int maxt = 0;
		std::size_t pos = 0;
		while ((pos = str.find(maxs, pos)) != std::string::npos) {
			maxt++;
			pos++;
		}
		if (maxh)
		{
			cout << maxs << " " << maxt << endl;
		}
		else
			cout << "No repetitions found!" << endl;
	}
	system("pause");
	return 0;
}
