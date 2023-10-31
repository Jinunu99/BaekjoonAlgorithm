#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		num[i] = a;
	}

	int min = *min_element(num.begin(), num.end());
	int max = *max_element(num.begin(), num.end());

	cout << min << " " << max;

	return 0;
}