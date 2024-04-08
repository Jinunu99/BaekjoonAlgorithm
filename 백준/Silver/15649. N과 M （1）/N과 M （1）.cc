// 15649번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = { 0 };
bool visit[9] = { false };
vector<int> v;

void dfs(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == true)
			continue;
		v.push_back(i);
		visit[i] = true;
		dfs(depth + 1);
		v.pop_back();
		visit[i] = false;
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = i;

	dfs(0);

	return 0;
}