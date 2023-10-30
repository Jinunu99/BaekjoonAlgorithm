#include <iostream>
using namespace std;

// 4673번

int main(void)
{
	int num[10001] = { 0 };
	for (int i = 1; i < 10000; i++)
	{
		int sum = i;
		while (sum <= 10000)
		{
			int temp = sum;
			while (temp / 10 != 0)
			{
				sum += temp % 10;
				temp /= 10;
			}
			sum += temp % 10;

			if(sum<= 10000)
				num[sum] = 1;
		}
	}
	for (int i = 1; i < 10001; i++)
	{
		if (num[i] == 0)
			cout << i << '\n';
	}

	return 0;
}