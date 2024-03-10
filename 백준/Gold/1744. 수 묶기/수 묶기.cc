#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> plus_q;
	priority_queue<int, vector<int>, greater<int>> minu_q;
	bool flag = false; // 0이 있는가
	int one = 0; // 1의 갯수

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;
		if (ipt == 1)
			one++;
		else if (ipt > 0)
			plus_q.push(ipt);
		else if (ipt == 0)
			flag = true;
		else
			minu_q.push(ipt);
	}

	int total = 0;
	while (!plus_q.empty())
	{
		int first, second;
		first = plus_q.top();
		plus_q.pop();
		if (plus_q.empty())
		{
			total += first;
		}
		else if(!plus_q.empty())
		{
			second = plus_q.top();
			plus_q.pop();
			total += first * second;
		}
	}

	while(!minu_q.empty())
	{
		int first, second;
		first = minu_q.top();
		minu_q.pop();
		if (!minu_q.empty())
		{
			second = minu_q.top();
			minu_q.pop();
			total += first * second;
		}
		else
		{
			if (flag == true)
				break;
			else
			{
				total += first;
			}
		}
	}

	cout << total + one;

	return 0;
}