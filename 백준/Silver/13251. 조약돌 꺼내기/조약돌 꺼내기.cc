#include <iostream>

using namespace std;

int main(void)
{
	int n, k;
	int arr[51];
	int total = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		total += arr[i]; // 전체 조약돌 갯수
	}
	
	cin >> k;

	double probability = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= k) // arr에 담겨있는 색깔에서 모두 같은 색일 확률을 구해야함
		{
			double p = 1;
			for (int j = 0; j < k; j++)
			{
				p *= (double)(arr[i] - j) / (total - j);
			}
			probability += p;
		}
	}

	cout << fixed;
	cout.precision(9);
	cout << probability;

	return 0;
}