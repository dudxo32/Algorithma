#include <iostream>

using namespace std;

int main()
{
	int n;
	int array[501]; // ���ڸ� ���� �迭
	
	int sum[501]; // ���� ���� �迭
	int sum2[501]; // ���� ���� �迭2

	fill_n(sum, 501, 0);
	fill_n(sum2, 501, 0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) // i=����
	{
		for (int j = 1; j <= i; j++) //j=�������� ����
		{
			cin >> array[j]; //���� ���� �Է�
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