#include <iostream>

using namespace std;

// 9095번

int main(void)
{
	int n;
	cin >> n;
	
	int dp[11] = { 0 };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		
		cout << dp[num] << '\n';
	}

	return 0;
}