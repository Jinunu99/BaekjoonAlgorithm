#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int arr[1000][3] = { 0 };

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	for (int i = 1; i < n; i++)
	{
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}

	sort(arr[n - 1], arr[n - 1] + 3);

	cout << arr[n - 1][0];

	return 0;
}