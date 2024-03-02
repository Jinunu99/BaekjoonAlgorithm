#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int visit[100001] = { 0 };

int bfs(int x)
{
	queue<pair<int, int>> q;
	q.push({ x, 0 });

	while (!q.empty())
	{
		int f = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (0 <= n && n <= 100000)
		{
			if (f == k)
				return depth;

			else
			{
				if (f + 1 <= 100000 && visit[f + 1] == 0)
				{
					q.push({ f + 1, depth + 1 });
					visit[f + 1] = 1;
				}
				if (f - 1 >= 0 && visit[f - 1] == 0)
				{
					q.push({ f - 1, depth + 1 });
					visit[f - 1] = 1;
				}
				if (2 * f <= 100000 && visit[2 * f] == 0)
				{
					q.push({ 2 * f, depth + 1 });
					visit[2 * f] = 1;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int depth = 0;
	depth = bfs(n);

	cout << depth;

	return 0;
}