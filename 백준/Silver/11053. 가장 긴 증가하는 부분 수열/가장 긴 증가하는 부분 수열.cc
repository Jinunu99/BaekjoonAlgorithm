#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 11053번

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

	int maxi = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (db[i] > db[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxi = max(maxi, dp[i]);
		
	}

	cout << maxi;

	return 0;
}