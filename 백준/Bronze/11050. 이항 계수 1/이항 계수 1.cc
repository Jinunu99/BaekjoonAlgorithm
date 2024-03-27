#include <iostream>

using namespace std;

int combination(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	else
		return combination(n - 1, k) + combination(n - 1, k - 1);
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	int result;
	result = combination(n, k);

	cout << result;

	return 0;
}