// 백트래킹 문제 하나 더 풀기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m;
int arr[51][51] = { 0 };
int result[51][51] = { 0 };
int min_dis = 987654321;
vector<pair<int, int>> chicken;
vector<pair<int, int>> v;
vector<int> total;

void cal_distance()
{
	for (int c = 0; c < m; c++)
	{
		// 선택된 치킨집 위치
		int x = v[c].first;
		int y = v[c].second;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] == 1 && result[i][j] == 0)
					result[i][j] = (abs(i - x) + abs(j - y));
				else if (arr[i][j] == 1)
				{
					result[i][j] = min(result[i][j], abs(i - x) + abs(j - y));
				}
			}
		}

		int t = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				t += result[i][j];
			}
		}
		total.push_back(t);
	}
}

void dfs(int start, int depth)
{
	if (depth == m) // 최대 m개 선택다했으면 최소 거리를 구하자
	{
		cal_distance();
		fill(result[0], result[51], 0);
		return;
	}

	for (int i = start; i < chicken.size(); i++)
	{
		v[depth] = chicken[i];
		dfs(i + 1, depth + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 2)
				chicken.push_back({ i,j }); // 치킨집 저장
		}
	}

	v.resize(m);
	dfs(0, 0);

	cout << *min_element(total.begin(), total.end());

	return 0;
}