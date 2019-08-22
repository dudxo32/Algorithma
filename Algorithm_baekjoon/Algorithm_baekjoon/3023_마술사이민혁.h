#include <iostream>
#include <vector>
using namespace std;

void start_3023()
{
	int r, c;
	char symbol;
	int A, B;
	cin >> r >> c;
	vector< vector<char> > ans(r*2, vector<char>(c*2, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> symbol;
			
			ans[i][j] = symbol;
		}
		cout << endl;
	}
	cin >> A >> B;
	if (A - 1 < r && B - 1 < c)
	{
		ans[A - 1][B - 1] = ans[A - 1][B - 1] == '#' ? '.' : '#';
	}

	//좌우
	for (int i = 0; i < r; i++)
	{
		for (int j = c; j < c*2; j++)
		{
			ans[i][j] = ans[i][((c*2)-1)-j];
		}
	}
	//위아래
	for (int i = r; i < r*2; i++)
	{
		for (int j = 0; j < c * 2; j++)
		{
			ans[i][j] = ans[((r * 2) - 1) - i][j];
		}
	}
	//에러 변경
	ans[A - 1][B - 1] = ans[A - 1][B - 1] == '#' ? '.' : '#';


	for (int i = 0; i  <  r*2; i++)
	{
		for (int j = 0; j < c*2; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	system("pause");
}