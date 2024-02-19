#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	int s_idx = 1, e_idx = 1;
	int count = 1;
	int sum = 1;

	while (e_idx != n)
	{
		if (sum == n)
		{
			count++;
			e_idx++;
			sum += e_idx;
		}
		else if (sum > n)
		{
			sum -= s_idx;
			s_idx++;
		}
		else // sum < n
		{
			e_idx++;
			sum += e_idx;
		}
	}
	cout << count;
	
	return 0;
}