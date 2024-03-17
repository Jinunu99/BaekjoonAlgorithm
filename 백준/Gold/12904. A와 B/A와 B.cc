#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	cin >> s;
	cin >> t;

	int size = t.size();
	while (t.size() != s.size())
	{
		char check;
		check = t[size - 1];

		if (check == 'A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		size--;
	}

	if (s == t)
		cout << 1;
	else
		cout << 0;

	return 0;
}