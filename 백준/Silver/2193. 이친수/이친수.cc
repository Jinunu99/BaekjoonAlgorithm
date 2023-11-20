#include <iostream>

using namespace std;

// 2193번

int main(void)
{
	int n;
	cin >> n;

	long long dp[91] = { 0 };
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];

	return 0;
}