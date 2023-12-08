#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

// 1753번

vector<pair<int, int>> db[20001];
int result[20001];

void dijkstra(int x)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, x });
	result[x] = 0; // 시작 노드는 가중치가 0임	

	while (!pq.empty())
	{
		int w = pq.top().first; // 현재까지의 가중치
		int v = pq.top().second; // 현재 나의노드
		pq.pop();

		// 이미 최소가중치가 저장되어있으면 그냥 무시
		if (result[v] < w)
			continue;

		for (int i = 0; i < db[v].size(); i++)
		{
			int next_w = w + db[v][i].first; // 현재 가중치에서 가야되는 가중치를 더해줌
			int next_v = db[v][i].second;

			// 지금 저장된 next_v가 원래 저장된 가중치보다 작으면 해당 가중치로 초기화 
			if (result[next_v] > next_w)
			{
				pq.push({ next_w, next_v });
				result[next_v] = next_w;
			}
		}
	}
}

int main(void)
{
	int n, e;
	int k;
	cin >> n >> e;
	cin >> k;

	
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		db[u].push_back({ w, v }); // 출발지 u -> { 가중치, 목적지 v }
	}
	
	fill(result + 1, result + n + 1, INF);

	dijkstra(k);

	for (int i = 1; i <= n; i++)
	{
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}

	return 0;
}