#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct xy {
	int x;
	int y;
};

bool compare(const xy& a, const xy& b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y < b.y;
	}
}

int main(void)
{
	int n;
	cin >> n;

	vector<xy> point;
	xy temp;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		temp.x = x;
		temp.y = y;

		point.push_back(temp);
	}
	
	sort(point.begin(), point.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << point[i].x << " " << point[i].y << "\n";
	}

	return 0;
}