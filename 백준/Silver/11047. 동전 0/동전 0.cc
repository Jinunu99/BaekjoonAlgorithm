#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 11047번

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);

	for (int i = n - 1; i >= 0; i--)
	{
		int c;
		cin >> c;
		coin[i] = c;
	}

	int count = 0;
	for (auto& c : coin)
	{
		count += k / c;
		k %= c;
	}

	cout << count;
	return 0;
}