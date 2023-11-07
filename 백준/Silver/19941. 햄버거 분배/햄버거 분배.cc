#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 19941번 햄버거 분배 풀기

int main(void)
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	vector<int> ham(n);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'H')
			ham[i] = 1;
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'P') // 사람이 나오면 범위내에 먹을 햄버거가 있는지 조사
		{
			for (int j = i - k; j <= i + k; j++)
			{
				if (j >= 0 && j < n && ham[j] == 1)
				{
					ham[j] = 0;
					count++;
					break;
				}
			}
		}
	}

	cout << count;
	return 0;
}