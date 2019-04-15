#include <iostream>

using namespace std;

void start_5585()
{
	int money;
	int changMoney;

	cin >> money;

	changMoney = 1000 - money;

	int m500 = changMoney / 500;
	int m100 = (changMoney % 500) / 100;
	int m50 = ((changMoney % 500) % 100) / 50;
	int m10 = (((changMoney % 500) % 100) % 50) / 10;
	int m5 = ((((changMoney % 500) % 100) % 50) % 10) / 5;
	int m1 = ((((changMoney % 500) % 100) % 50) % 10) % 5;

	int result = m500+m100+m50+m10+m5+m1;

	cout << result;

	system("pause");
}

