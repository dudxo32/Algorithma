#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void start_4307()
{
	int m;//케이스 개수
	int n;// 개미수
	int l;//막대 길이
	int *array = new int[1000000];
	cin >> m;

	while (m--)
	{
		cin >> l >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> array[i];
		}
	}
	sort(array, array + n + 1);

	int center = ceil(l / 2);

	int minIndex = 1;
	int min = abs(array[minIndex] - center);

	int maxIndex = 1;
	int max = abs(array[maxIndex] - center);

	for (int i = 2; i <= n; i++)
	{
		minIndex = abs(array[i] - center) < min ? i : minIndex;
		maxIndex = abs(array[i] - center) > max ? i : maxIndex;
	}
	int minResult = abs(1 - array[minIndex]) > abs(l - array[minIndex]) ? abs(l - array[minIndex]) : abs(1 - array[minIndex]);
	cout << minResult;

	int maxResult = abs(1 - array[maxIndex]) < abs(l - array[maxIndex]) ? abs(l - array[maxIndex]) : abs(1 - array[maxIndex]);

	system("pause");
}
