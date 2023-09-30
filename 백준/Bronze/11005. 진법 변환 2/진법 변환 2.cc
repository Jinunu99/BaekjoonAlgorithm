#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	string result;
	int n, b;
	cin >> n >> b;

	while (n != 0) {
		int r = n % b;

		if (r < 10) {
			result += (char)('0' + r);
		}
		else {
			result += (char)('A' + r - 10);
		}

		n /= b;
	}
	reverse(result.begin(), result.end());

	cout << result;
	
	return 0;
}