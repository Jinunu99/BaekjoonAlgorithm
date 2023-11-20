#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 10773번

int main(void)
{
	vector<int> stk;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
			stk.pop_back();
		else
			stk.push_back(input);
	}

	int sum = accumulate(stk.begin(), stk.end(), 0);

	cout << sum;
	return 0;
}