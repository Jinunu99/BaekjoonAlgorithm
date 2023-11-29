#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 7562번

int main(void)
{
	vector<int> db;
	vector<int> total;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		db.push_back(a);
	}

	int cmp = db[0];
	total.push_back(cmp);

	for (int i = 1; i < n; i++)
	{
		if (cmp + db[i] > db[i])
		{
			cmp = cmp + db[i];
			total.push_back(cmp);
		}
		else
		{
			cmp = db[i];
			total.push_back(cmp);
		}
	}
	
	int maxi = *max_element(total.begin(), total.end());

	cout << maxi;
	return 0;
}