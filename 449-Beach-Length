#include <iostream>
using namespace std;

int main()
{

	while (!cin.eof())
	{
		char input[10000];
		cin >> input[0];
		int m = 0;
		while (!cin.eof())
		{
			m++;
			cin.get(input[m]);
			if ((input[m] == '\n' && input[m - 1] == '\n')||cin.eof())
				break;
		}
		char kingdom[200][200];
		int row = 0;
		int col = 0;
		int colc = 0;
		for (int i = 0; i < m; i++)
		{
			if (input[i] != '\n')
			{
				kingdom[row][col] = input[i];
				col++;
			}
			else
			{
				colc = col;
				row++;
				col = 0;
			}
		}
		if (row == 0)
		{
			break;
		}
		int beach = 0;
		if (row == 1)
		{
			for (int i = 0; i < colc; i++)
			{
				if (colc == 1)
				{
					break;
				}
				else if (i == 0)
				{
					if (kingdom[0][i] != kingdom[0][i + 1])
					{
						beach++;
					}
				}
				else if (i == colc - 1)
				{
					if (kingdom[0][i] != kingdom[0][i - 1])
					{
						beach++;
					}
				}
				else
				{
					if (kingdom[0][i] != kingdom[0][i - 1])
					{
						beach++;
					}
					if (kingdom[0][i] != kingdom[0][i + 1])
					{
						beach++;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < row; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j < colc; j++)
					{
						if (colc == 1)
						{
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
								break;
							}
							else
							{
								break;
							}
						}
						else if (j == 0)
						{
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i + 1][j] != kingdom[i][j])
							{
								beach++;
							}
						}
						else if (j == colc - 1)
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j - 1])
							{
								beach++;
							}
						}
						else
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j - 1])
							{
								beach++;
							}
						}
					}
				}
				else if (i == row - 1 && i % 2 == 0)
				{
					for (int j = 0; j < colc; j++)
					{
						if (colc == 1)
						{
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
								break;
							}
							else
							{
								break;
							}
						}
						else if (j == 0)
						{
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
						}
						else if (j == colc - 1)
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
						}
						else
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j - 1])
							{
								beach++;
							}
						}
					}
				}
				else if (i == row - 1 && i % 2 != 0)
				{
					for (int j = 0; j < colc; j++)
					{
						if (colc == 1)
						{
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
								break;
							}
							else
							{
								break;
							}
						}
						else if (j == 0)
						{
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j + 1])
							{
								beach++;
							}
						}
						else if (j == colc - 1)
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
						}
						else
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j + 1])
							{
								beach++;
							}
						}
					}
				}
				else if (i % 2 != 0)
				{
					for (int j = 0; j < colc; j++)
					{
						if (colc == 1)
						{
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
								break;
							}
							else
							{
								break;
							}
						}
						else if (j == 0)
						{
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j + 1])
							{
								beach++;
							}
						}
						else if (j == colc - 1)
						{
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
						}
						else
						{
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j + 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
						}
					}
				}
				else
				{
					for (int j = 0; j < colc; j++)
					{
						if (colc == 1)
						{
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
								break;
							}
							else
							{
								break;
							}
						}
						else if (j == 0)
						{
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
						}
						else if (j == colc - 1)
						{
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j - 1])
							{
								beach++;
							}
						}
						else
						{
							if (kingdom[i][j] != kingdom[i + 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i + 1][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i - 1][j - 1])
							{
								beach++;
							}
							if (kingdom[i][j] != kingdom[i][j + 1])
							{
								beach++;
							}
						}
					}
				}
			}
		}
		cout << beach / 2 << endl;
	}
	return 0;
}
