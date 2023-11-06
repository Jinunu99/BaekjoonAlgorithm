#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1449번

int main(void)
{
	int n, l;
	cin >> n >> l;

	vector<int> water;
	for (int i = 0; i < n; i++)
	{
		int spot;
		cin >> spot;

		water.push_back(spot);
	}
	sort(water.begin(), water.end());

	int temp = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp < water[i])
		{
			temp = water[i] + l - 1;
			count++;
		}
	}

	cout << count;

	return 0;
}