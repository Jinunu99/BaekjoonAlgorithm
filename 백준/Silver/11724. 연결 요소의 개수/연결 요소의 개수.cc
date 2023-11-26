#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 11724번

int n, m;
int check[10001] = { 0 };
vector<int> list[1001];

void dfs(int x)
{
	check[x] = 1;

	for (auto i : list[x])
	{
		if (check[i] == 0)
		{
			dfs(i);
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
			dfs(i);
		}
	}

	cout << cnt;

	return 0;
}