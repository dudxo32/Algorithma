#include <iostream>
#include "1931_회의실배정.h"
#include "1932_정수삼각형.h"
#include "1965_상자넣기.h"
#include "2290_LCDTest.h"
#include "2302_극장좌석.h"
#include "2577_숫자의개수.h"
#include "3023_마술사이민혁.h"
#include "4307_개미.h" 
#include "5585_거스름돈.h"
#include "9084_동전.h"
#include "11066_파일합치기.h"
#include "11052_카드구매하기.h"

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
	///							구현
	//숫자의개수
	//start_2577();

	//마술사이민혁
	//start_3023();

	//LCD TEST
	//start_2290();


	///							Greedy Algorithm
	//회의실 배정 
	//start_1931();	

	//거스름돈
	//start_5585();


	///							Dynamic Algorithm
	//정수삼각형
	//start_1932();

	//상자넣기
	//start_1965();

	//극장좌석
	//start_2302();

	//동전
	//start_9084();

	//파일합치기
	//start_11066();

	//카드구매하기
	//start_11052();



	///							The Others
	//개미 
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
		//오른 왼
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

		//위 아래
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