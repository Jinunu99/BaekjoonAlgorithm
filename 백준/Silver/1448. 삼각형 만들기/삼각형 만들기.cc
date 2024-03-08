#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int arr[1000002] = { 0 };
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;
		arr[i] = ipt;
	}

	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - arr[i + 1] < arr[i + 2])
		{
			cout << arr[i] + arr[i + 1] + arr[i + 2];
			return 0;
		}
	}
	cout << -1;


	return 0;
}