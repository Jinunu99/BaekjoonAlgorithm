#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int maxi = 0;
vector<vector<int>> v;
vector<int> visit;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visit[x] = 1;

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		for (int i = 0; i < v[f].size(); i++)
		{
			int next = v[f][i];
			if (visit[next] == 0)
			{
				q.push(next);
				visit[next] = 1;
				maxi++;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<int> check(n + 1);
	
	v.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		maxi = 0;
		visit.assign(n + 1, 0);

		bfs(i);
		
		check[i] = maxi;
	}

	int total_max = *max_element(check.begin(), check.end());

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == total_max)
			cout << i << " ";
	}
	return 0;
}