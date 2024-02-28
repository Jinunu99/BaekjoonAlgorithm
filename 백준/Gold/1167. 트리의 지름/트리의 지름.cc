#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<vector<pair<int, int>>> arr; // pair<목적지, 가중치>
vector<int> check;
vector<int> total;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	check[x] = 1;
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		for (pair<int, int> i : arr[f])
		{
			if (check[i.first] == 0)
			{
				q.push(i.first);
				check[i.first] = 1;
				total[i.first] = total[f] + i.second;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr.resize(n + 1);
	check.resize(n + 1, 0);
	total.resize(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int st;
		cin >> st;
		while (1)
		{
			int de, h;
			cin >> de;
			if (de == -1)
				break;
			cin >> h;
			arr[st].push_back({ de, h });
		}
	}

	bfs(1);
	int maxi_1, maxi_2, max_idx;
	maxi_1 = *max_element(total.begin(), total.end());
	max_idx = max_element(total.begin(), total.end()) - total.begin();
	
	fill(check.begin(), check.end(), 0);
	fill(total.begin(), total.end(), 0);

	bfs(max_idx);
	maxi_2 = *max_element(total.begin(), total.end());
	if (maxi_1 < maxi_2)
	{
		cout << maxi_2;
		return 0;
	}

	cout << maxi_1;
	return 0;
}