// 2588번

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a;
	cin >> b;

	cout << a * (b % 10) << endl;
	cout << a * (b % 100 / 10) << endl;
	cout << a * (b % 1000 / 100) << endl;
	cout << a * b;

	return 0;
}