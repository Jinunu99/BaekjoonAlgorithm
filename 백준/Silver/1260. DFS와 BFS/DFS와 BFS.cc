#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> vec;
vector<int> check;

void dfs(int x)
{
	check[x] = 1;
	cout << x << " ";

	for (int i : vec[x])
	{
		if (check[i] == 0)
			dfs(i);
	}
}

void bfs(int x)
{
	queue<int>q;
	q.push(x);
	check[x] = 1;
	cout << x << " ";
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		for (int i : vec[f])
		{
			if (check[i] == 0)
			{
				q.push(i);
				check[i] = 1;
				cout << i << " ";
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;
	vec.resize(n + 1);
	check.resize(n + 1, 0);
	
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);

	fill(check.begin(), check.end(), 0);
	cout << "\n";

	bfs(v);


	return 0;
}