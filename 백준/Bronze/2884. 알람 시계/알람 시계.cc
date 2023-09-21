#include <iostream>

using namespace std;

int main(void)
{
	int h, m;

	cin >> h >> m;

	if (m >= 45 && m < 60)
	{
		m -= 45;
	}
	else if (m == 0)
	{
		h -= 1;
		m = 15;
	}
	else
	{
		h -= 1;
		m = 60 - (45 - m);
	}

	if (h < 0)
		h = 23;

	cout << h << " " << m;

	return 0;
}