#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	double grade[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> grade[i];
	}
	double max = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < grade[i])
			max = grade[i];
		sum += grade[i];
	}

	double total = sum / max * 100 / n;
	cout << total;
	
	return 0;
}