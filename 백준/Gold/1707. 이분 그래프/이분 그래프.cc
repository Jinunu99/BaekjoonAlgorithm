#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int v, e;
vector<vector<int>> arr;
vector<int> visit;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		for (int i = 0; i < arr[f].size(); i++)
		{
			int next = arr[f][i];
			if (visit[next] == 0) // 방문을 안했다
			{
				if (visit[f] == 1)
				{
					visit[next] = 2;
					q.push(next);
				}
				else
				{
					visit[next] = 1;
					q.push(next);
				}
			}
		}
	}
	return;
}

bool is_Graph()
{
	for (int i = 1; i < v; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			int next = arr[i][j];
			if (visit[i] == visit[next])
				return false;
		}
	}
	return true;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		arr.clear();
		visit.clear();
		arr.resize(v + 1);
		visit.resize(v + 1, 0);

		int find;
		for (int j = 0; j < e; j++)
		{
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		for (int j = 1; j <= v; j++)
		{
			if (!visit[j])
				bfs(j);
		}

		int flag;
		flag = is_Graph();

		if (flag == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}