#include <iostream>
#include <vector>

using namespace std;

void start_2290()
{
	int s, n;
	cin >> s >> n;
	int mod;
	int line=0;
	while (mod / 10 != 0)
	{
		mod = n / 10;
		line++;
	}

	cout << line;

	//vector<vector<char> >
}