#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>

#define INF 987654321
using namespace std;

// 1261번

int m, n;
int db[100][100];
int check[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	check[x][y] = 0;
	q.push({ x, y });

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (db[nx][ny] == 0) // 벽을 부수지 않을 때
			{
				next = check[x][y];
			}
			else // 벽을 부숴야할 때
			{
				next = check[x][y] + 1;
			}

			if (check[nx][ny] > next) // next값이 원래 저장되어있는 것보다 작으면
			{
				q.push({ nx, ny });
				check[nx][ny] = next;
			}
		}
	}
}

int main(void)
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			db[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			check[i][j] = INT_MAX;
		}
	}

	bfs(0, 0);

	cout << check[n - 1][m - 1];

	return 0;
}