#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#define INF 987654321
using namespace std;

// 7576번

int m, n;
int db[1000][1000];
int check[1000][1000];
int dx[4] = {1, 0, -1, 0}; // 아, 왼, 위, 오
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (db[nx][ny] == 0 && check[nx][ny] == 0)
			{
				q.push({ nx, ny });
				check[nx][ny] = check[x][y] + 1;
			}
		}
	}
}

int main(void)
{
	cin >> m >> n;

	int end = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;

			db[i][j] = a;

			if (a == 1)
				q.push({ i, j });
			else if (a == 0)
				end++;
		}
	}
	if (end == 0) // 원래 다 익어있다면
	{
		cout << 0;
		return 0;
	}
	
	bfs();

	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (db[i][j] == 0 && check[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			if (maxi < check[i][j])
			{
				maxi = check[i][j];
			}
		}
	}
	
	// 최소 갯수 출력자리
	cout << maxi;

	return 0;
}