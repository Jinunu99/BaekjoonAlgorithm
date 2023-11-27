#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 2667번

int n;
int cnt;
int list[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int i, int j)
{
	list[i][j] = 0;
	cnt++;
	
	for (int r = 0; r < 4; r++)
	{
		int nx = i + dx[r];
		int ny = j + dy[r];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		
		if (list[nx][ny] == 1)
		{
			dfs(nx, ny);
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '1')
				list[i][j] = 1;
			else
				list[i][j] = 0;
		}
	}
	vector<int> total;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (list[i][j] == 1)
			{
				cnt = 0;
				dfs(i, j);
				total.push_back(cnt);
			}
		}
	}

	cout << total.size() << '\n';
	sort(total.begin(), total.end());
	for (int i = 0; i < total.size(); i++)
	{
		cout << total[i] << "\n";
	}


	return 0;
}