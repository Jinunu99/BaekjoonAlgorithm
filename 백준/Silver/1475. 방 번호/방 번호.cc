#include <iostream>
#include <algorithm>

using namespace std;

// 1475번

int main(void)
{
	int pla_set[10] = { 0 };
	int num;
	cin >> num;

	while (1)
	{
		int n = num % 10;
		
		if (n == 6)
		{
			if (pla_set[6] <= pla_set[9])
			{
				pla_set[6]++;
			}
			else
			{
				pla_set[9]++;
			}
		}
		else if (n == 9)
		{
			if (pla_set[9] <= pla_set[6])
			{
				pla_set[9]++;
			}
			else
			{
				pla_set[6]++;
			}
		}
		else
			pla_set[n]++;
	
		num /= 10;
		if (num == 0)
			break;
	}

	int max = *max_element(pla_set, pla_set + 10);
	cout << max;
	return 0;
}