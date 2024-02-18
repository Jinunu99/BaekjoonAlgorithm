#include <iostream>
using namespace std;

int arr[1025][1025] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	int ipt;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ipt;
			arr[i][j] = arr[i][j - 1] + ipt;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		int total = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++)
		{
			total += (arr[j][y2] - arr[j][y1 - 1]);
		}
		cout << total << '\n';
	}

	return 0;
}