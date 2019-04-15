#include <iostream>
#include <algorithm>
#include <math.h>
/*
개미가 반대로 가는건 아무런 의미가 없음
길이의 중간값(홀수라면 올림값)에서 각 길이의 뺀후 절대값 비교
뺄셈의 절대값이 가장 작은 위치에서 각 양끝 0,l 을  빼고 그중 작은 값이 가장 빨리 떨어 지는 경우
뺄셈의 절대값이 가장 큰 위치에서 각 양끝 0,l 을 빼고 그중 가장 큰 값이 가장 늦게 떨어 지는 경우
*/
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

		sort(array, array + n + 1);

		int mid = ceil(l / 2);
		int maxM = abs(mid - array[1]);
		int minM = abs(mid - array[1]);
		int maxIndex=1, minIndex=1;
		for (int i = 2; i <= n; i++)
		{
			if (abs(mid - array[i]) > maxM)
			{
				maxM = abs(mid - array[i]);
				maxIndex = i;
			}
			if (abs(mid - array[i]) < minM)
			{
				minM = abs(mid - array[i]);
				minIndex = i;
			}
		}

		cout << min(abs(l - array[minIndex]), abs(array[minIndex] - 0)) << " "; //짧은경우
		cout << max(abs(l - array[maxIndex]), abs(array[maxIndex] - 0)) << endl;//긴경우
	}
	
}
