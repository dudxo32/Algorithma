#include <iostream>
#include <algorithm>

using namespace std;

void start_11066()
{
	int t;//�׽�Ʈ ���̽� ����
	int k;//�Ҽ����� ���� ��
	int array[501];
	int sum[501];//�հ�

	
	cin >> t;
	while (t--)
	{
		fill_n(array, 501, 0);
		fill_n(sum, 501, 0);
		cin >> k;
		int** cal = new int*[k + 1];
		for (int i = 0; i <= k; i++)
		{
			cal[i] = new int[k + 1];
		}
		for (int i = 1; i <= k; i++)
		{
			cin >> array[i];
			sum[i] = sum[i - 1] + array[i];
		}
		//�ʱ�ȭ
		for (int i = 0; i <= k; i++)
		{
			cal[i][i] = 0;
		}
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				cal[i][j] = 0;
			}
		}


		for (int l = 1; l < k; l++)
		{
			for (int i = 1; i <= k - l; i++)
			{
				int j = i + l;
				cal[i][j] = 9999999;
				for (int k = i; k <= j - 1; k++)
				{
					cal[i][j] = min(cal[i][j], cal[i][k] + cal[k + 1][j] + sum[j] - sum[i-1]);
				}

			}
		}

		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				cout << "[" << cal[i][j] << "]";
			}
			cout << endl;
		}

		cout << cal[1][k] << endl;
	}
	system("pause");
}
