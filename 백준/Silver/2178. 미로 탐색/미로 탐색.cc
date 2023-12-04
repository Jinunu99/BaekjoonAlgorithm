#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 2178번
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int db[100][100] = { 0 };
int check[100][100] = { 0 };

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	check[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (db[nx][ny] == 1 && check[nx][ny] == 0)
			{
				q.push({ nx, ny });
				check[nx][ny] = check[x][y] + 1;
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			db[i][j] = str[j] - '0';
		}
	}

	bfs();	

	cout << check[n - 1][m - 1];

	return 0;
}