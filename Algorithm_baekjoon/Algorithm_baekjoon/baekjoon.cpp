#include <iostream>
#include "1931_ȸ�ǽǹ���.h"
#include "1932_�����ﰢ��.h"
#include "1965_���ڳֱ�.h"
#include "2290_LCDTest.h"
#include "2302_�����¼�.h"
#include "2577_�����ǰ���.h"
#include "3023_�������̹���.h"
#include "4307_����.h" 
#include "5585_�Ž�����.h"
#include "9084_����.h"
#include "11066_������ġ��.h"
#include "11052_ī�屸���ϱ�.h"

vector<vector<int> > roate(vector< vector<int> > a)
{
	vector< vector<int> > temp(a.size(), vector<int>(a.size(), 0));

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			temp[j][a.size() - 1 - i] = a[i][j];
		}
	}
	return temp;
}

int main()
{
	///							����
	//�����ǰ���
	//start_2577();

	//�������̹���
	//start_3023();

	//LCD TEST
	//start_2290();


	///							Greedy Algorithm
	//ȸ�ǽ� ���� 
	//start_1931();	

	//�Ž�����
	//start_5585();


	///							Dynamic Algorithm
	//�����ﰢ��
	//start_1932();

	//���ڳֱ�
	//start_1965();

	//�����¼�
	//start_2302();

	//����
	//start_9084();

	//������ġ��
	//start_11066();

	//ī�屸���ϱ�
	//start_11052();



	///							The Others
	//���� 
	//start_4307(); 
	vector<vector<int>> key = { {0,0,0},{1,0,0}, {0,1,1} };
	vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };
	vector<vector<int>> temp(key);
	vector< vector<int> > ans(key.size(), vector<int>(key.size(), 0));

	bool answer = false;

	bool switchRL = true;
	bool switchUD = true; //up

	for (int r = 0; r < 4; r++)
	{
		switchRL = true;
		switchUD = true;
		//���� ��
		for (int i = 0; i < 2; i++)
		{
			for (int q = 0; q < key.size(); q++)
			{
				for (int i = 0; i < key.size(); i++)
				{
					for (int j = 0; j < key.size(); j++)
					{
						if (switchRL && j <= q)
							temp[i][j] = 0;
						else if (!switchRL && j >= 2 - q)
							temp[i][j] = 0;
						else
						{
							if (switchRL)
								temp[i][j] = key[i][j - (q + 1)];
							else
								temp[i][j] = key[i][j + (q + 1)];
						}
						if (ans[i][j] = temp[i][j] + lock[i][j] == 1) answer = true;
						else answer = false;
					}
				}
				if (answer) break;
			}
			if (answer) break;
			switchRL = !switchRL;
		} 

		//�� �Ʒ�
		for (int i = 0; i < 2; i++)
		{
			for (int q = 0; q < key.size(); q++)
			{
				for (int i = 0; i < key.size(); i++)
				{
					for (int j = 0; j < key.size(); j++)
					{

						if (switchUD && i >= 2 - q)
							temp[i][j] = 0;
						else if (!switchUD && i <= q)
							temp[i][j] = 0;
						else
						{
							if (switchUD)
								temp[i][j] = key[i + (q + 1)][j];
							else
								temp[i][j] = key[i - (q + 1)][j];
						}
						if (ans[i][j] = temp[i][j] + lock[i][j] != 1) break;
					}
				}
				if (answer) break;
			}
			if (answer) break;
			switchUD = !switchUD;
		}

		if (answer) break;
		key = roate(key);

	}
	system("pause");
}