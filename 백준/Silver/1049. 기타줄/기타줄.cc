#include <iostream>
#include <climits>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	int pack = INT_MAX, ele = INT_MAX;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < pack)
			pack = a;
		if (b < ele)
			ele = b;
	}

	int count = 0;
	if (ele != 0 && (pack / ele) < 6) // 낱개로 사는것이 손해일때
	{
		while (n > 0)
		{
			int c = n / 6; // 패키지 갯수

			if (c != 0)
			{
				count += pack * c;
				n -= 6 * c;
			}
			else // 남은거 중에
			{
				if (n*ele>pack) // 패키지로 사는게 나은지
				{
					count += pack;
					n -= 6;
				}
				else // 낱개로 사는게 나은지
				{
					count += ele * n;
					n = 0;
				}
			}
		}
	}
	else // 낱개로 사는것이 이득일때
	{
		count = ele * n;
	}
	cout << count;

	return 0;
}