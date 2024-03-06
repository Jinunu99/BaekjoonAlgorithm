#include <iostream>
using namespace std;

int lecture[100000] = { 0 };

int main(void)
{
	int m, n;
	cin >> m >> n;
	
	int high = 0;
	int low = 0; // 최소 블루레이 크기
	for (int i = 0; i < m; i++)
	{
		cin >> lecture[i];
		high += lecture[i];
		if (low < lecture[i])
			low = lecture[i];
	}

	while (low <= high)
	{
		int mid = (low + high) / 2;

		int sum = 0; // 블루레이의 갯수
		int inner = 0; // 블루레이에 현재 몇분의 강의가 담겨있는지
		for (int i = 0; i < m; i++)
		{
			if (inner + lecture[i] > mid)
			{
				sum += 1;
				inner = lecture[i];
			}
			else
				inner += lecture[i];
		}
		if (inner != 0)
			sum += 1;
		
		if (sum > n) // 블루레이 갯수가 넘쳤으니 블루레이의 크기를 늘려보자
		{
			low = mid + 1;
		}
		else // 블루레이 갯수가 넘치지 않았으니 블루레이의 크기를 줄여보자
		{
			high = mid - 1;
		}
	}
	cout << low;

	return 0;
}