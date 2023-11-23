#include <iostream>

using namespace std;

// 2606번 dfs로 구현

int num;
int com[101][101] = { 0 };
int check[101] = { 0 };
int cnt = 0;

void dfs(int x)
{
	cnt++;
	check[x] = 1;

	for (int i = 1; i <= num; i++)
	{
		if (check[i] == 0 && com[x][i] == 1)
		{
			dfs(i);
		}
	}
}

int main(void)
{
	cin >> num;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		com[a][b] = 1;
		com[b][a] = 1;
	}

	dfs(1);

	cout << cnt - 1; // 1번 컴퓨터는 제외해야하니깐

	return 0;
}