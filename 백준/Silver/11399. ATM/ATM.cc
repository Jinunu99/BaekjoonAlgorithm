#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 11399번

int main(void)
{
	int n;
	cin >> n;
	vector<int> time;
	
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		time.push_back(t);
	}

	sort(time.begin(), time.end());
	
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j <= i; j++)
		{
			sum += time[j];
		}
		result += sum;
	}

	cout << result;

	return 0;
}