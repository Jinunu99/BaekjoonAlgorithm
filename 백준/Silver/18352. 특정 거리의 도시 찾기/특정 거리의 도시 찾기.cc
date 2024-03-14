// 18352
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector<vector<int>> v;
vector<int> arr;
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	arr[x] = 0;

	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		for (int i = 0; i < v[f].size(); i++)
		{
			int next = v[f][i]; // 연결된 원소
			if (arr[next] == -1)
			{
				q.push(next);
				arr[next] = arr[f] + 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k >> x;

	v.resize(n + 1); // 인접리스트
	arr.resize(n + 1, -1); // 누적거리

	for (int i = 0; i < m; i++) // 도로 갯수만큼 입력 받기
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	bfs(x);

	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == k)
		{
			cout << i << '\n';
			flag = true;
		}
	}

	if (flag == false)
		cout << -1;

	return 0;
}