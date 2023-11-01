#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1158번

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> first;
	vector<int> result;
	for (int i = 1; i <= n; i++)
	{
		first.push_back(i);
	}

	int idx = -1; // 시작 인덱스
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		while (1)
		{
			idx = (idx + 1) % n;
			if (first[idx] != 0)
			{
				count++;
			}
			else
			{
				continue;
			}

			if (count == k)
			{
				result.push_back(first[idx]);
				first[idx] = 0;
				break;
			}
		}
	}
	cout << "<";
	for (int i = 0; i < n - 1; i++)
	{
		cout << result[i] << ", ";
	}
	cout << result[n - 1] << ">";

	return 0;
}