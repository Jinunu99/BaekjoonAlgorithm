#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pri_q;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;
		pri_q.push(ipt);
	}

	int sum = 0;
	while (pri_q.size() != 1)
	{
		int first, second;
		first = pri_q.top();
		pri_q.pop();
		second = pri_q.top();
		pri_q.pop();

		int inner_sum;
		inner_sum = first + second;
		sum += inner_sum;
		pri_q.push(inner_sum);
	}
	
	cout << sum;

	return 0;
}