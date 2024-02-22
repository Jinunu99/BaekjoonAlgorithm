// 1012번

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int t, m, n, k;
int arr[50][50] = { 0 };
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j }); //q.push(make_pair(i, j)) 과 동일

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (arr[nx][ny] == 1)
			{
				q.push({ nx, ny });
				arr[nx][ny] = 0;
			}
		}
	}
}

int main(void)
{
	cin >> t;
	
	for (int test = 0; test < t; test++)
	{
		cin >> m >> n >> k;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 1)
				{
					bfs(i, j);
					count++;
				}
			}
		}

		cout << count << '\n';
	}

	

	return 0;
}