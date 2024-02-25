#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> ipt;
	vector<char> result;
	
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ipt.push_back(a);
	}

	int count = 1;
	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		int su = ipt[i];

		if (su >= count) // 입력수가 count보다 크거나 같으면 push해줘야함
		{
			while (su >= count)
			{
				stk.push(count++);
				result.push_back('+');
			}
			stk.pop();
			result.push_back('-');
		}
		else // pop을 해줘야함
		{
			if (stk.top() == su)
			{
				stk.pop();
				result.push_back('-');
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}


	return 0;
}