#include <iostream>
#include <algorithm>
#include <math.h>
/*
���̰� �ݴ�� ���°� �ƹ��� �ǹ̰� ����
������ �߰���(Ȧ����� �ø���)���� �� ������ ���� ���밪 ��
������ ���밪�� ���� ���� ��ġ���� �� �糡 0,l ��  ���� ���� ���� ���� ���� ���� ���� ���� ���
������ ���밪�� ���� ū ��ġ���� �� �糡 0,l �� ���� ���� ���� ū ���� ���� �ʰ� ���� ���� ���
*/
using namespace std;

void start_4307()
{
	int m;//���̽� ����
	int n;// ���̼�
	int l;//���� ����
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

		cout << min(abs(l - array[minIndex]), abs(array[minIndex] - 0)) << " "; //ª�����
		cout << max(abs(l - array[maxIndex]), abs(array[maxIndex] - 0)) << endl;//����
	}
	
}
