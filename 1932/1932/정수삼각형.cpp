#include <iostream>

using namespace std;

int main()
{
	int n;
	int array[501]; // ���ڸ� ���� �迭
	int preArray[500];
	int sum[501]; // ���� ���� �迭

	fill_n(sum, 501, 0);
	

	cin >> n;
	
	for (int i = 1; i <= n; i++) // i=����
	{
		for (int j = 1; j <= i; j++) //j=�������� ����
		{
			cin >> array[j];
		}
		
		if (sum[1] == 0) sum[1] = sum[0] = array[i];
		else
		{
			for (int k = 1; k < i; k++)
			{
				int temp = sum[k];  //38��°�� k+1 �� ���� sum���� �ٲ����� ������

				if (sum[k] != 0)
				{
					int a = temp + array[k];
					sum[k] < a ? sum[k] = a : sum[k];
				}
			//	else
				//	sum[k] = temp + array[k];
				sum[k+1] = temp + array[k+1];
			}
		}
	/*	cout<< i <<"��" << endl;
		for (int q = 1; q <= i; q++)
			cout << "[" << sum[q] << "]-";
		cout << endl <<endl;*/
	}
	int max = sum[1];
	for (int i = 2; i <= n; i++)
	{
		max < sum[i] ? max = sum[i] : max;
	}
	cout << max;
	system("pause");
}