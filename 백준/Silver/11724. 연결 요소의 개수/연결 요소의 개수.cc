#include <iostream>
#include <vector>
#include <algorithm>

// 11724
using namespace std;

int n, m;
vector<vector<int>> lst;
vector<bool> check;

void dfs(int x)
{
	if (check[x] == true)
		return;

	check[x] = true;

	for (int i = 0; i < lst[x].size(); i++)
	{
		int num = lst[x][i];

		if (check[num] == false)
		{
			dfs(num);
		}
	}
}

int main(void)
{
	cin >> n >> m;

	lst.resize(n + 1);
	check.resize(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		lst[a].push_back(b);
		lst[b].push_back(a);
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
			count++;
		}
	}
	cout << count;



	return 0;
}