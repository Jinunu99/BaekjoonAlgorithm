#include <iostream>

using namespace std;

// 10844번

long long dp[101][10] = { 0 };

int main(void)
{
	long long sum = 0;
	
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
		}	
	}

	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}

	sum %= 1000000000;

	cout << sum;

	return 0;
}