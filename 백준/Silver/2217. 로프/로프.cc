#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int arr[100000] = { 0 };
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] * (i + 1))
			max = arr[i] * (i + 1);
	}
	cout << max;

	return 0;
}