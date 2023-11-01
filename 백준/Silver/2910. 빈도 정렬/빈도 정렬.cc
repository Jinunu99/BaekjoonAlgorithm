#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2910번

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}


int main(void)
{
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> msg;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		bool found = false;
		for (auto& j : msg)
		{
			if (j.first == num)
			{
				found = true;
				j.second++;
				break;
			}
		}

		if (found == false)
		{
			msg.push_back(make_pair(num, 1));
		}
	}

	stable_sort(msg.begin(), msg.end(), cmp);
	for (auto& i : msg)
	{
		while (i.second != 0)
		{
			cout << i.first << " ";
			i.second--;
		}
	}
	
	return 0;
}