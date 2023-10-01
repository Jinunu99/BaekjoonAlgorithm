#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	queue<int> que;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		que.push(i);
	}

	while (que.size() != 1) {
		que.pop();

		if (que.size() != 1) {
			int p;
			p = que.front();
			que.pop();
			que.push(p);
		}
		else {
			break;
		}
	}

	cout << que.front();
	return 0;
}