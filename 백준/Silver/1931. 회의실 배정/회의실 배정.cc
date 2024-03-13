#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}

	sort(v.begin(), v.end(), cmp);

	int count = 1;
	int s = v[0].first;
	int e = v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= e)
		{
			s = v[i].first;
			e = v[i].second;
			count++;
		}
	}
	cout << count;

	return 0;
}