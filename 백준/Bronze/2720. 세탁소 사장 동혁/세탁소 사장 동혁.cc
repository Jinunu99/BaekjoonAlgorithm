#include <iostream>

using namespace std;

// 2720번

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int pay;
		int q, d, n, p;
		cin >> pay;

		q = pay / 25;
		pay = pay - (25 * q);

		d = pay / 10;
		pay = pay - (10 * d);

		n = pay / 5;
		pay = pay - (5 * n);

		p = pay / 1;
		cout << q << " " << d << " " << n << " " << p << '\n';
	}

	return 0;
}