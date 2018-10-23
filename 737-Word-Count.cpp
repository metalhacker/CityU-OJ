#include <iostream>
#include <string>
using namespace std;

class words
{
public:
	string name;
	int count;
	words()
	{
		name = "";
		count = 0;
	}
	void addCount()
	{
		count += 1;
	}
};

class Dictionary
{
public:
	int numOfWords;
	words myWords[10000];
	void addWord(string w)
	{
		myWords[numOfWords].name = w;
		myWords[numOfWords].count = 1;
		numOfWords += 1;
	}
	bool check(string w)
	{
		for (int i = 0; i < numOfWords; i++)
		{
			if (myWords[i].name == w)
			{
				return true;
			}
		}
		return false;
	}
	void addWordCount(string w)
	{
		for (int i = 0; i < numOfWords; i++)
		{
			if (myWords[i].name == w)
			{
				myWords[i].addCount();
			}
		}
	}
	void sort()
	{
		for (int i = 0; i < numOfWords; i++)
		{
			for (int j = 0; j < numOfWords - 1; j++)
			{
				if (myWords[i].name < myWords[j].name)
				{
					words temp;
					temp = myWords[i];
					myWords[i] = myWords[j];
					myWords[j] = temp;
				}
			}
		}
	}
	void output()
	{
		for (int i = 0; i < numOfWords; i++)
		{
			cout << myWords[i].name << ' ' << myWords[i].count << endl;
		}
	}
	Dictionary()
	{
		numOfWords = 0;
	}
};


int main()
{
	string word;
	Dictionary text;
	while (cin >> word)
	{
		if (text.numOfWords == 0)
		{
			text.addWord(word);
		}
		else if (text.check(word) == false)
		{
			text.addWord(word);
		}
		else
		{
			text.addWordCount(word);
		}
	}
	text.sort();
	text.output();
	return 0;
}
