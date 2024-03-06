#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	priority_queue<int, vector<int>, greater<int>> pri_que;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;

		if (ipt == 0)
		{
			if (pri_que.empty())
				cout << 0 << '\n';
			else
			{
				cout << pri_que.top() << '\n';
				pri_que.pop();
			}
		}
		else
		{
			pri_que.push(ipt);
		}
	}

	return 0;
}