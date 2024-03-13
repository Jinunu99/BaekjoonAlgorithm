#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<string> str;
	int height[26] = { 0 };
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		str.push_back(s);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < str[i].size(); j++)
		{
			height[str[i][j] - 'A'] += pow(10, str[i].size() - j - 1);
		}
	}

	sort(height, height + 26, cmp); // 내림차순으로 정렬

	int i = 0;
	int count = 9;
	int total = 0;
	while (height[i] != 0)
	{
		total += height[i] * count;
		count--;
		i++;
	}
	cout << total;

	return 0;
}