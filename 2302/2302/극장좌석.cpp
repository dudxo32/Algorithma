#include <iostream>

using namespace std;

class sit
{
public:
	int count;//����� ��
	int lastNum;//���������� �ִ� ����� ��

	sit() { 
		count = 0;
		lastNum = 0;
	}
};
int main()
{
	int n; //�¼��� ����
	int m; //������ ����
	int mArray[41]; //������ ��ȣ��
	int size[41];//������ ���ز������� �ִ�
	sit nArray[41]; //�¼� ��ȣ

	nArray[0].count = 1;
	nArray[0].lastNum = 1;
	nArray[1].count = 1;
	nArray[1].lastNum = 1;
	nArray[2].count = 2;
	nArray[2].lastNum = 1;

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> mArray[i];
	}
	
	size[1] = mArray[1]-1;
	for (int i = 2; i <= m; i++)
	{
		size[i] = mArray[i] - (mArray[i - 1] + 1);
	}
	size[m+1] = n - mArray[m];
	
	int max=size[1];
	for (int i = 2; i <= m + 1; i++)
	{
		max < size[i] ? max = size[i] : max = max;
	}
	
	for (int i = 3; i <= max; i++)
	{
		nArray[i].count = nArray[i - 1].lastNum + nArray[i - 1].count;
		nArray[i].lastNum = nArray[i - 1].count;
	}
	
	int result=1;
	for (int i = 1; i <= m + 1; i++)
	{
		result *= nArray[size[i]].count;
	}

	cout << result;

	system("pause");
}

