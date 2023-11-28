#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

// 7562번

int n;
int Sx, Sy, Ex, Ey;
int check[300][300] = { 0 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (x == Ex && y == Ey)
		{
			cout << check[x][y] << '\n';
			while (!q.empty())
				q.pop();
			break;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (check[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				check[nx][ny] = check[x][y] + 1;
			}
		}
	}
}

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> n;
		cin >> Sx >> Sy;
		cin >> Ex >> Ey;

		bfs(Sx, Sy);
		memset(check, 0, sizeof(check));
	}


	return 0;
}