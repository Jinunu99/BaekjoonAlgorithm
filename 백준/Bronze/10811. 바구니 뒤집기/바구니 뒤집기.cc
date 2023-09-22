#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m;
	vector<int> bag;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		bag.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		reverse(bag.begin() + a - 1, bag.begin() + b);
	}

	for (int i = 0; i < n; i++)
		cout << bag[i] << " ";

	return 0;
}