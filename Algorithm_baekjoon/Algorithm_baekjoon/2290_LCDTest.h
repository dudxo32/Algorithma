#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_column(int s, int count, int num)
{
	if (count == 0)
	{
		if (num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 0) return true;
	}
	else if (count == (2 * s + 2) / 2)
	{
		if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9) return true;
	}
	else
	{
		if (num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) return true;
	}
	
	return false;
}

int check_row(int s, int count, int num) //0없음 1왼쪽 2오른 3둘다
{
	if (0 < count && count < (2 * s + 2)/2)
	{
		if (num == 5 || num == 6)
			return 1;
		else if (num == 1 || num == 2 || num == 3 || num == 7)
			return 2;
		else
			return 3;
	}
	else if ((2 * s + 2)/2 < count && count < 2 * s + 2)
	{
		if (num == 2)
			return 1;
		if (num == 1 || num == 3 || num == 4 || num == 5 || num == 7 || num == 9)
			return 2;
		else
			return 3;
	}
	else
		return 0;
}

void start_2290()
{
	int s;
	vector<int> number;
	string n;
	cin >> s;
	cin >> n;

	for (int i = 0; i < n.length(); i++)
	{
		char temp = n[i];
		int a = 0;
		a = temp - '0';
		number.push_back(a);
	}
	int line = n.length();

	int count;
	for (int i = 0; i < 2*s+3; i++)
	{
		for (int j = 0; j < line; j++)
		{
			if (i == 0 || i == (2 * s + 2) / 2 || i == 2 * s + 2)
			{	
				count = 0;
				if (check_column(s, i, number[j]))
				{
					cout << ' ';

					for (int q = 0; q < s; q++) //s만큼
					{
						cout << '-';
					}
					cout << ' '; //0--0
					cout << ' ';
				}
				else
				{
					for (int i = 0; i < s + 2; i++) //s만큼
					{
						cout << ' ';
					}
					cout << ' ';
				}
			}
			else
			{
				int check = check_row(s, i, number[j]);
				if (check == 1)
				{
					cout << "|";
					for (int i = 0; i < s + 1; i++)
					{
						cout << " ";
					}
					cout << ' ';
				}
				else if (check == 2)
				{
					for (int i = 0; i < s + 1; i++)
					{
						cout << " ";
					}
					cout << "|";
					cout << " ";

				}
				else if (check == 3)
				{
					cout << "|";
					for (int i = 0; i < s; i++)
					{
						cout << " ";
					}
					cout << "| ";
				}
			}
		}
		cout << endl;
	}
	
	system("pause");
}