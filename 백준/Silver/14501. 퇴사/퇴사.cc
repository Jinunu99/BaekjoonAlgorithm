// 14501번
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n + 2, 0);
	vector<pair<int, int>> advice(n + 1);
	
	for (int c = 0; c < n; c++)
	{
		int t, p;
		cin >> t >> p;

		advice[c + 1] = { t, p };
	}

	for (int i = n; i > 0; i--)
	{
		if (i + advice[i].first > n + 1)
		{
			v[i] = v[i + 1];
		}
		else
		{
			v[i] = max(v[i + 1], advice[i].second + v[i + advice[i].first]);
		}
	}
	cout << v[1];

	return 0;
}