#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int count = 0;
	int find;

	for (int i = 666;; i++)
	{
		string temp = to_string(i);
		if (temp.find("666") != string::npos)
		{
			count++;
			if (count == n)
			{
				find = i;
				break;
			}
		}
	}

	cout << find;

	return 0;
}