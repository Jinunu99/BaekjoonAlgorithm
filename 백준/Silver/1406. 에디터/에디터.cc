#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// 1406번

int main(void)
{
	deque<char> l;
	deque<char> r;

	string str;
	int n;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		l.push_back(str[i]);
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char cmd;
		char plus;
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> plus;
		}
		
		if (cmd == 'L')
		{
			if (l.size() != 0)
			{
				r.push_front(l[l.size() - 1]);
				l.pop_back();
			}
		}
		else if (cmd == 'D')
		{
			if (r.size() != 0)
			{
				l.push_back(r[0]);
				r.pop_front();
			}
		}
		else if (cmd == 'B')
		{
			if (l.size() != 0)
			{
				l.pop_back();
			}
		}
		else if (cmd == 'P')
		{
			l.push_back(plus);
		}
	}
	
	for (int i = 0; i < l.size(); i++)
	{
		cout << l[i];
	}
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i];
	}

	return 0;
}