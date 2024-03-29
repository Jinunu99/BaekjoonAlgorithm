#include <iostream>

using namespace std;

int main(void)
{
	int k, n;
	int test;
	cin >> test;

	int arr[15][15] = { 0 };
	for (int i = 1; i <= 14; i++)
	{
		arr[0][i] = i;
	}
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}

	for (int i = 0; i < test; i++)
	{
		cin >> k;
		cin >> n;

		cout << arr[k][n] << '\n';
	}

	return 0;
}