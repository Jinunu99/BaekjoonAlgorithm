#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int arr[500][500] = { 0 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (i == j)
				break;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
			{
				arr[i][j] += arr[i - 1][j];
			}
			else
			{
				int max_value = max(arr[i - 1][j], arr[i - 1][j - 1]);
				arr[i][j] += max_value;
			}
		}
	}

	
	sort(arr[n - 1], arr[n - 1] + n);

	cout << arr[n - 1][n - 1];

	return 0;
}