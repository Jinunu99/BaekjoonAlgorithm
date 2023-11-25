#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 13023번

vector<int> list[2001];
int check[2001] = { 0 };
int n, m;
bool arr = false;

void dfs(int x, int depth)
{
	if (depth == 5 || arr == true)
	{
		arr = true;
		return;
	}

	check[x] = 1;
	for (auto i : list[x])
	{
		if (check[i] == 0)
		{
			dfs(i, depth + 1);
		}
	}
	check[x] = 0;
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

	for (int i = 0; i < n; i++)
	{		
		dfs(i, 1);

		if (arr == true)
		{
			cout << "1";
			return 0;
		}
	}
	cout << "0";

	return 0;
}