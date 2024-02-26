#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct cmp {
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, cmp> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;
		if (ipt == 0 && !q.empty())
		{
			cout << q.top() << '\n';
			q.pop();
		}
		else if (ipt == 0 && q.empty())
		{
			cout << 0 << '\n';
		}
		else
		{
			q.push(ipt);
		}
	}

	return 0;
}