#include <iostream>

using namespace std;

int main(void)
{
	double a, b;
	cin >> a >> b;

	cout << fixed;
	cout.precision(9);

	cout << a / b;

	return 0;
}