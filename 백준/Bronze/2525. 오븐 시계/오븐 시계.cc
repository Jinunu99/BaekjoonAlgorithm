#include <iostream>

using namespace std;

int main(void)
{
	int h, m, time;

	cin >> h >> m;
	cin >> time;

	m += time % 60;
	if (m >= 60)
	{
		m -= 60;
		h += 1;
	}

	h += time / 60;
	if (h >= 24)
		h -= 24;

	cout << h << " " << m;

	return 0;
}