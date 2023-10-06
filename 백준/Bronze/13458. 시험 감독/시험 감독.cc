#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 13458번

int main(void)
{
	int n;
	vector<int> people;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		people.push_back(a);
	}

	int b, c;
	cin >> b >> c;
	long long sum = 0;

	for (int i = 0; i < n; i++)
	{
		if ((people[i] - b) % c == 0 && people[i] - b > 0)
		{
			sum += (people[i] - b) / c;
		}
		else if ((people[i] - b) % c != 0 && people[i] - b > 0)
		{
			sum += (people[i] - b) / c + 1;
		}
	}

	sum += n;

	cout << sum;

	return 0;
}