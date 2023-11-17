#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1463번

int main(void)
{
	int n;
	cin >> n;
	vector<int> num(n + 1);

	num[1] = 0;

	if (n > 1)
	{
		for (int i = 2; i <= n; i++)
		{
			num[i] = num[i - 1] + 1;
			if (i % 3 == 0)
				num[i] = min(num[i / 3] + 1, num[i]);
			if (i % 2 == 0)
				num[i] = min(num[i / 2] + 1, num[i]);
		}
	}

	cout << num[n];

	return 0;
}