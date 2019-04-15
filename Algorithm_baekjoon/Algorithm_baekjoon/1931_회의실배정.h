#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class MyClass
{
public:
	int start;
	int end;

	MyClass() {};
};

int cmp(MyClass  &a, MyClass &b)
{
	if (a.end == b.end)	return a.start < b.start;
	else return a.end < b.end;
}
//���� ������ ������ �ð��� ������ 1-4 // 5-5 // 4-5 �� ��� 4-5�� �Ѿ� ������

void start_1931()
{
	int n;
	MyClass array[100001];

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> array[i].start;
		cin >> array[i].end;
	}
	sort(array, array + n + 1, cmp);

	int a = array[1].end;
	int count = 1;
	for (int i = 2; i <= n; i++)
	{
		if (array[i].start >= a)
		{
			a = array[i].end;
			count++;
		}
	}
	cout << count;
	system("pause");
}