#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 11724번

int n, m;
int check[10001] = { 0 };
vector<int> list[1001];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	check[x] = 1;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (auto i : list[front])
		{
			if (check[i] == 0)
			{
				q.push(i);
				check[i] = 1;
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		list[a].push_back(b);
		list[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 0)
		{
			cnt++;
			bfs(i);
		}
	}

	cout << cnt;

	return 0;
}