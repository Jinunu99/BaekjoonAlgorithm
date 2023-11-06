#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1931번

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> meet;

	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;

		meet.push_back(make_pair(s, e));
	}

	sort(meet.begin(), meet.end(), compare);

	int e = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (meet[i].first >= e)
		{
			e = meet[i].second;
			count++;
		}
	}

	cout << count;
	return 0;
}