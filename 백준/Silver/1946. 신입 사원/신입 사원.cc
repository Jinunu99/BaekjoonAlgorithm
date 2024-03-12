// 1946번 신입사원

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		int n;
		vector<pair<int, int>> v;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int f, s;
			cin >> f >> s;
			v.push_back({ f, s });
		}
		
		sort(v.begin(), v.end());

		int temp = 0;
		int count = 1;

		for (int i = 1; i < n; i++)
		{
			if (v[temp].second > v[i].second)
			{
				count++;
				temp = i;
			}
		}

		cout << count << '\n';
	}

	return 0;
}