#include <iostream>

using namespace std;

int main()
{
	int n;
	int array[501]; // 숫자를 담을 배열
	int preArray[500];
	int sum[501]; // 합을 담을 배열

	fill_n(sum, 501, 0);
	

	cin >> n;
	
	for (int i = 1; i <= n; i++) // i=층수
	{
		for (int j = 1; j <= i; j++) //j=층에서의 개수
		{
			cin >> array[j];
		}
		
		if (sum[1] == 0) sum[1] = sum[0] = array[i];
		else
		{
			for (int k = 1; k < i; k++)
			{
				int temp = sum[k];  //38번째줄 k+1 에 의해 sum값이 바껴ㅑ서 오류남

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
	/*	cout<< i <<"층" << endl;
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