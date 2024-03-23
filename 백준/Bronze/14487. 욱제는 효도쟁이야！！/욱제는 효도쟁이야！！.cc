#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int m = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		total += input;
		if (input > m)
			m = input;
	}
	cout << total - m;

	return 0;
}