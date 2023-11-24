#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 1260번 dfs와 bfs

int n, m, v;
int db[1001][1001] = { 0 };
int c_DFS[1001] = { 0 };
int c_BFS[1001] = { 0 };
int cnt = 0;
vector<int> v_DFS;
vector<int> v_BFS;

void dfs(int x)
{
	c_DFS[x] = 1;
	v_DFS.push_back(x);

	for (int i = 1; i <= n; i++)
	{
		if (c_DFS[i] == 0 && db[x][i] == 1)
		{
			dfs(i);
		}
	}
}

void bfs(int x)
{
	queue<int> q;
	q.push(x); // 첫번째 방문
	c_BFS[x] = 1;

	while (!q.empty()) // 큐가 안비어있다면 실행
	{
		int f = q.front(); // 큐 앞에 있는것 저장
		q.pop();
		v_BFS.push_back(f); // 방문했다고 표시

		for (int i = 1; i <= n; i++)
		{
			if (c_BFS[i] == 0 && db[f][i] == 1) // 아직 방문한적 없는데 연결되어있는 노드
			{
				q.push(i); // 저장
				c_BFS[i] = 1; // 이제 방문 표시
			}
		}
	}

}


int main(void)
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		db[a][b] = 1;
		db[b][a] = 1;
	}


	dfs(v);
	for (int i = 0; i < v_DFS.size(); i++)
	{
		cout << v_DFS[i] << " ";
	}
	cout << "\n";


	bfs(v);
	for (int i = 0; i < v_BFS.size(); i++)
	{
		cout << v_BFS[i] << " ";
	}

	return 0;
}