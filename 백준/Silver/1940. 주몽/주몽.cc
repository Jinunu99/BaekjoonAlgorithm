#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1940
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	vector<int> ipt;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		ipt.push_back(num);
	}
	sort(ipt.begin(), ipt.end());

	int count = 0;
	int s_idx = 0, e_idx = n - 1;
	while (s_idx < e_idx)
	{
		if (ipt[s_idx] + ipt[e_idx] == m)
		{
			count++;
			s_idx++;
			e_idx--;
		}
		else if (ipt[s_idx] + ipt[e_idx] < m)
		{
			s_idx++;
		}
		else
		{
			e_idx--;
		}
	}
	cout << count;
	
	return 0;
}