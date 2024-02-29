// 1920
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

void find(int s, int l, int f)
{
	if (s > l)
	{
		cout << "0" << '\n';
		return;
	}
	int m = (s + l) / 2;
	if (vec[m] == f)
	{
		cout << "1" << '\n';
		return;
	}
	else if (vec[m] < f) // 중간 값보다 클때
		return find(m + 1, l, f);
	else // 중간 값보다 작을때
		return find(s, m - 1, f);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int find_num;
		cin >> find_num;

		find(0, n - 1, find_num);
	}

	return 0;
}