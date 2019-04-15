#pragma once
#include <iostream>

using namespace std;

class box
{
public:
	int size;
	int count;
	box() {

	}
	box(int s, int c) {
		size = s;
		count = c;
	}
};

void start_1965()
{
	int n;
	box array[1001];
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		array[i].size = a;
		array[i].count = 1;
	}


	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (array[j].size < array[i].size &&
				array[j].count >= array[i].count - 1)
				array[i].count = array[j].count + 1;
		}
	}

	int max = array[1].count;
	for (int i = 2; i <= n; i++)
	{
		if (max < array[i].count)
			max = array[i].count;
	}

	cout << max;
	
	system("pause");
}


