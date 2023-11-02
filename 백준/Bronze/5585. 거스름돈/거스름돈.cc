#include <iostream>

using namespace std;

// 5585번

int main(void)
{
	int change[6] = { 500, 100, 50, 10, 5, 1 };
	int pay;
	cin >> pay;
	pay = 1000 - pay;

	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		int n = 0;
		n += (pay / change[i]);
		count += n;
		pay = pay - (change[i] * n);
		if (pay == 0)
			break;
	}
	cout << count;
	

	return 0;
}