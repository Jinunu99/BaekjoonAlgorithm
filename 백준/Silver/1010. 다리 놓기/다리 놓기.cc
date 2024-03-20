// 조합공식 nCr = n-1Cr-1 + n-1Cr

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combination(int n, int r, vector<vector<int>> &v)
{
	if (r == 0 || r == n)
	{
		v[n][r] = 1;
		return 1;
	}

	if (v[n][r])
	{
		return v[n][r];
	}
	else
	{
		v[n][r] = combination(n - 1, r - 1, v) + combination(n - 1, r, v);
		return v[n][r];
	}
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		int result;
		cin >> n >> m;

		vector<vector<int>> v;
		v.resize(m + 1, vector<int>(n + 1, 0));
		
		cout << combination(m, n, v) << "\n";
	}

	return 0;
}