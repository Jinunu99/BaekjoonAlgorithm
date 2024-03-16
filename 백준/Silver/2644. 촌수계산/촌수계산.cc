#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int s, e;
int m;
vector<vector<int>> v;
vector<int> visit;
int d;

void dfs(int start, int end, int depth)
{
	if (start == end)
	{
		d = depth;
		return;
	}
	
	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		if (visit[next] == 0)
		{
			visit[next] = 1;
			dfs(next, end, depth + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> s >> e;
	cin >> m;

	v.resize(n + 1);
	visit.resize(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(s, e, 0);

	if (d == 0)
		cout << -1;
	else
		cout << d;

	return 0;
}