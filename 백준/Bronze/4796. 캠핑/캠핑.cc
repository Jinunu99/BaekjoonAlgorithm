#include <iostream>

using namespace std;

// 4796번

int main(void)
{
	int l, p, v;
	int count = 1;
	while (1)
	{
		int sum = 0;
		cin >> l >> p >> v;
		
		if (l == 0 && p == 0 && v == 0)
			break;

		sum += l * (v / p);
		v = v - (p * (v / p));

		if (v <= l)
			sum += v;
		else
			sum += l;

		cout << "Case " << count << ": " << sum << endl;
		count++;
	}

	return 0;
}