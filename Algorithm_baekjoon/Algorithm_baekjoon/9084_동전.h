#include <iostream>

using namespace std;

void start_9084()
{
	int t, n, m; //테스트 개수, 동전가지 수, 금액
	int array[10001];

	int money[21];

	cin >> t;

	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> money[i];
		}
		cin >> m;
		fill_n(array, 10001, 0);
		array[0] = 1;

		for (int i = 1; i <= n; i++)//동전 개수
		{
			for (int j =1; j <= m; j++)
			{
				if (j - money[i] < 0)
				{
					array[j] = array[j] + 0;
				}
				else if (j - money[i] == 0)
				{
					array[j] = array[j] + 1;
				}
				else
				{
					array[j] = array[j] + array[j - money[i]];
				}
				
			}
		}
	/*	for (int i = 1; i <= n; i++)//동전 개수
		{
			for (int j = money[i]; j <= m; j++)
			{
				array[j] = array[j] + array[j - money[i]];
			}
		}*/


		cout << array[m] << endl;
	}

	system("pause");
}