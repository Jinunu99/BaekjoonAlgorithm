#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// 17298번

int main(void)
{
	int n;
	cin >> n;

	vector<int> nge; // 처음 입력값
	stack<int> temp;
	vector<int> result; // 결과 담기

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		nge.push_back(num);
	}

	
	for (int i = n - 1; i >= 0; i--)
	{
		while (!temp.empty() && temp.top() <= nge[i])
			temp.pop();

		if (temp.empty())
			result.push_back(-1);
		else
			result.push_back(temp.top());

		temp.push(nge[i]);
	}

	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}