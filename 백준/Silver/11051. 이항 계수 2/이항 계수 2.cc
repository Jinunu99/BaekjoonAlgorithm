#include <iostream>

using namespace std;

int arr[1001][1001] = { 0 };

int main(void)
{
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		arr[i][0] = 1;
		arr[i][1] = i;
		arr[i][i] = 1;
	}

	for (int i = 3; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			arr[i][j] %= 10007;
		}
	}
	cout << arr[n][k];

	return 0;
}