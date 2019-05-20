#include <iostream>
#include <algorithm>

using namespace std;

void start_11052()
{
	int n;//구매할 카드의 개수
	int array[1001];//카드팩 가격
	int dp[1001];
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> array[i];
	}
	fill_n(dp, 1001, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int temp = dp[j - i] + array[i];
			dp[j] = max(dp[j], temp);
		}
	}
	cout << dp[n];

	system("pause");
}