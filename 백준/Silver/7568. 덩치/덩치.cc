#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 7568번

int main(void)
{
	int n;
	vector<pair<int, int>> person;
	cin >> n;
	vector<int> rank(n);

	for (int i = 0; i < n; i++)
	{
		int w, h;
		cin >> w >> h;
		person.push_back(make_pair(w, h));
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (person[i].first < person[j].first && person[i].second < person[j].second)
				count++;
		}
		rank[i] = count + 1;
	}

	for (int i = 0; i < n; i++)
	{
		cout << rank[i] << " ";
	}
	return 0;
}