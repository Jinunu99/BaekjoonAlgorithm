#include <iostream>


using namespace std;

int main(void)
{
	int first_n;
	cin >> first_n;

	int max_5 = first_n / 5; // 최대 5kg의 개수
	int print = -1;

	while (max_5 >= 0)
	{
		int count = 0; // 설탕 봉지 개수
		int n = first_n; // 입력한 n 받아오기

		count += max_5; // 5kg 봉지 갯수
		n -= 5 * count;

		if (n % 3 == 0) // 3kg으로 나눠 떨어져야함
		{
			count += n / 3;

			if (print == -1) // 처음 저장될 때
			{
				print = count;
			}
			else {
				if (print > count)
					print = count;
			}
		}
		max_5--;
	}

	cout << print;

	return 0;
}