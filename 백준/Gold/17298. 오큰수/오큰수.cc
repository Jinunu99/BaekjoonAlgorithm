#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> stk;
	vector<int> ipt(n, 0);
	vector<int> result(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> ipt[i];

		while (!stk.empty() && ipt[stk.top()] < ipt[i])
		{
			result[stk.top()] = ipt[i];
			stk.pop();
		}
		stk.push(i);
	}

	while (!stk.empty())
	{
		result[stk.top()] = -1;
		stk.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}
}