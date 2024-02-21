// 1253번
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int ipt[2001] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> ipt[i];
	}
	sort(ipt, ipt + n);

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int s = 0, e = n - 1;
		while (s < e)
		{
			if (ipt[s] + ipt[e] == ipt[i])
			{
				if (s == i)
				{
					s++;
				}
				else if (e == i)
				{
					e--;
				}
				else
				{
					count++;
					break;
				}
			}
			else if (ipt[s] + ipt[e] > ipt[i])
			{
				e--;
			}
			else if (ipt[s] + ipt[e] < ipt[i])
			{
				s++;
			}
		}
	}
	cout << count;

	return 0;
}