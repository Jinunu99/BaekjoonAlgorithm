// 14940번 쉬운 최단거리

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m; // n은 행, m은 열
int arr[1000][1000] = { 0 };
int visit[1000][1000] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		int i_x = q.front().first;
		int i_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int fx = i_x + dx[i];
			int fy = i_y + dy[i];

			if (fx < 0 || fx >= n || fy < 0 || fy >= m)
				continue;

			if (arr[fx][fy] == 1 && visit[fx][fy] == 0)
			{
				q.push({ fx, fy });
				visit[fx][fy] = visit[i_x][i_y] + 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int st_x, st_y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int ipt;
			cin >> ipt;
			if (ipt == 2)
			{
				st_x = i;
				st_y = j;
			}
			arr[i][j] = ipt;
		}
	}

	bfs(st_x, st_y);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
				cout << -1 << " ";
			else
				cout << visit[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}