#include <iostream>

using namespace std;

int main()
{
	int n;
	int array[501]; // 숫자를 담을 배열
	
	int sum[501]; // 합을 담을 배열
	int sum2[501]; // 합을 담을 배열2

	fill_n(sum, 501, 0);
	fill_n(sum2, 501, 0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) // i=층수
	{
		for (int j = 1; j <= i; j++) //j=층에서의 개수
		{
			cin >> array[j]; //각층 숫자 입력
		}
		
		if (sum[1] == 0) {
			sum[1] = sum[0] = array[i];
			sum2[1] = sum2[0] = array[i];
		}
		else
		{
			for (int k = 1; k < i; k++)
			{
				int temp = sum[k] + array[k];
				if (sum2[k] < temp)
				{
					sum2[k] = temp;
				}
				temp = sum[k] + array[k + 1];
				if (sum2[k + 1] < temp)
				{
					sum2[k + 1] = temp;
				}
			}
			for (int q = 1; q <= i; q++)
			{
				sum[q] = sum2[q];
			}
		}
	}

	int max = sum2[1];
	for (int i = 2; i <= n; i++)
	{
		max < sum2[i] ? max = sum2[i] : max;
	}
	cout << max;
}