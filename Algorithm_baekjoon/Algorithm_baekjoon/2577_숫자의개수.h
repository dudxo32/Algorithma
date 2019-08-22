#include <iostream>

using namespace std;

void start_2577()
{
	int a, b, c;
	int ans[10] = {0,};
	cin >> a >> b >> c;


	int sum = a * b * c;
	int rest=1;

	while (sum != 0)
	{

		ans[sum % 10]++;

		sum = sum / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << ans[i] << endl;
	}

	system("pause");
}