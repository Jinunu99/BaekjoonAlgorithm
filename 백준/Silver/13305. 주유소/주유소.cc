#include <iostream>

using namespace std;
int dis[100000] = { 0 };
int city[100000] = { 0 };
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> dis[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> city[i];
	}

	int mini = city[0];
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (mini > city[i])
			mini = city[i];

		total += mini * dis[i];
	}
	cout << total;

	return 0;
}