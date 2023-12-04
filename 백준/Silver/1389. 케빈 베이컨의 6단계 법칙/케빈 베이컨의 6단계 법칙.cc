#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cstring>
using namespace std;

vector<int> total(1); // 전체의 케빈 베이컨의 수를 저장
vector<int> sum; // 개인의 케빈 베이컨수 저장
int check[101] = { 0 };
int n, m;
vector<int> relation[101];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	check[x] = 1;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		int size = relation[front].size();
		for (int i = 0; i < size; i++)
		{
			int next = relation[front][i];
			if (check[next] == 0)
			{
				q.push(next);
				check[next] = check[front] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i != x)
		{
			sum.push_back(check[i] - 1);
		}
	}
}


int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sum.clear();
		memset(check, 0, sizeof(check));
		bfs(i);
		
		int s = accumulate(sum.begin(), sum.end(), 0);
		total.push_back(s);
	}

	int mini = min_element(total.begin() + 1, total.begin() + n + 1) - total.begin();

	cout << mini;


	return 0;
}