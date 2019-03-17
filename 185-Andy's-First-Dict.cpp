#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string>svec;

int main()
{
	string line;
	//bool flag = 1;
	//int index = 0;
	while (getline(cin, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (!isalpha(line[i]))
			{
				line[i] = ' ';
			}
		}
		stringstream linein(line);
		string word;
		while (linein >> word)
		{
			if (true)
			{
				string temp;
				for (int i = 0; i < word.length(); i++)
				{
					if (isalpha(word[i]))
					{
						temp.push_back(tolower(word[i]));
					}
				}
				if (find(svec.begin(), svec.end(), temp) == svec.end())
				{
					svec.push_back(temp);
				}
			}
		}
	}
	sort(svec.begin(), svec.end());
	for (int i = 0; i < svec.size(); i++)
	{
		cout << svec[i] << endl;
	}
	//system("pause");
	return 0;
}
