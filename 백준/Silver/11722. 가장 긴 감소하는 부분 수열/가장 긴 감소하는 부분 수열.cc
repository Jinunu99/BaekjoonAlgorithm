#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 11722번

int main(void)
{
	int n;
	cin >> n;
	vector<int> db;
	int dp[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		db.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (db[j] > db[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp, dp + n);

	return 0;
}