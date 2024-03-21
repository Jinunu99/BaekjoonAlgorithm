#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visit[201][201] = { 0 };
int now[3];
int send[6] = { 0, 0, 1, 1, 2, 2 };
int rece[6] = { 1, 2, 0, 2, 0, 1 };
vector<int> result;

void bfs()
{
	queue<pair<int, int>> q; // 한번도 나오지 않은 용량들을 전부 큐에 넣기 위함
	q.push({ 0, 0 });
	visit[0][0] = 1;
	result.push_back(now[2]);

	while (!q.empty())
	{
		pair<int, int> f = q.front();
		q.pop();
		// 현재 a, b, c에 물의 상태
		int a = f.first;
		int b = f.second;
		int c = now[2] - a - b;
		
		for (int i = 0; i < 6; i++)
		{
			int next[3] = {a, b, c};

			next[rece[i]] += next[send[i]]; // 반복문에 따라 물이 옮겨진다
			next[send[i]] = 0; // 일단 보낸곳의 물통을 0으로 초기화함

			if (next[rece[i]] > now[rece[i]]) // 받은 물통이 넘치게되면
			{
				next[send[i]] = next[rece[i]] - now[rece[i]];	// 넘치는 양만 원래의 다시 물통에 넣어준다
				next[rece[i]] = now[rece[i]];	// 받은 물통에는 꽉차게 담겨있다
			}

			if (!visit[next[0]][next[1]])
			{
				visit[next[0]][next[1]] = 1;
				q.push({ next[0], next[1] });
				
				if (next[0] == 0)
					result.push_back(next[2]);
			}
		}
	}
}

int main(void)
{
	int a, b, c;
	cin >> now[0] >> now[1] >> now[2]; // 각 물통의 최대용량

	bfs();

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";


	return 0;
}