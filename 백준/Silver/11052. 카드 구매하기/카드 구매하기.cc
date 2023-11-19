#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 11052번

int main(void)
{
	int n;
	cin >> n;
	vector<int> dp(n+1);

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		dp[i] = num;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];

	return 0;
}