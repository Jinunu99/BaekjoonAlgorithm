#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int num;
	int sum[100001] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
	return 0;
}