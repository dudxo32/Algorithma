#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void start_3023()
{
		int r, c;
		char symbol;
		int A, B;

		cin >> r >> c;

		vector< vector<char> > ans(r * 2, vector<char>(c * 2, 0));

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> symbol;
				ans[i][j] = symbol;
			}
		}
		cin >> A >> B;
		if (A - 1 < r && B - 1 < c)
		{
			ans[A - 1][B - 1] = ans[A - 1][B - 1] == '#' ? '.' : '#';
		}

		//좌우
		for (int i = 0; i < r; i++)
		{
			for (int j = c; j < c * 2; j++)
			{
				ans[i][j] = ans[i][((c * 2) - 1) - j];
			}
		}
		//위아래
		for (int i = r; i < r * 2; i++)
		{
			for (int j = 0; j < c * 2; j++)
			{
				ans[i][j] = ans[((r * 2) - 1) - i][j];
			}
		}
		//에러 변경
		ans[A - 1][B - 1] = ans[A - 1][B - 1] == '#' ? '.' : '#';


		for (int i = 0; i < r * 2; i++)
		{
			for (int j = 0; j < c * 2; j++)
			{
				cout << ans[i][j];
			}
			cout << endl;
		}

}

void start_3023_r()
{
	while (true)
	{


		srand((unsigned int)time(0));

		char s[2] = { '.', '#' };
		int r, c;
		char symbol;
		int A, B;

		r = rand() % (50 - 1 + 1) + 1;
		c = rand() % (50 - 1 + 1) + 1;
		cout << "r,c" << r << "," << c << endl;

		vector< vector<char> > ans(r * 2, vector<char>(c * 2, 0));

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				symbol = s[rand() % 2];

				ans[i][j] = symbol;
			}
		}


		A = rand() % ((2 * r) - 1 + 1) + 1;
		B = rand() % ((2 * c) - 1 + 1) + 1;
		cout << "A,B" << A << "," << B << endl;

		if (A - 1 < r && B - 1 < c)
		{
			ans[A - 1][B - 1] = ans[A - 1][B - 1] == '#' ? '.' : '#';
		}

		//좌우
		for (int i = 0; i < r; i++)
		{
			for (int j = c; j < c * 2; j++)
			{
				ans[i][j] = ans[i][((c * 2) - 1) - j];
			}
		}
		//위아래
		for (int i = r; i < r * 2; i++)
		{
			for (int j = 0; j < c * 2; j++)
			{
				ans[i][j] = ans[((r * 2) - 1) - i][j];
			}
		}
		//에러 변경
		ans[A - 1][B - 1] = ans[A - 1][B - 1] == '#' ? '.' : '#';


		for (int i = 0; i < r * 2; i++)
		{
			for (int j = 0; j < c * 2; j++)
			{
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	system("pause");
}
