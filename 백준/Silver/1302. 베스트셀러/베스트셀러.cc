#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// 1302번

int main(void)
{
	int n;
	cin >> n;
	map<string, int> book;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (book.find(str) != book.end())
		{
			book[str]++;
		}
		else
			book.insert({ str,1 });
	}

	int max = 0;
	string result;
	for (auto iter = book.begin(); iter != book.end(); iter++)
	{
		if (max < iter->second)
		{
			max = iter->second;
			result = iter->first;
		}
	}

	cout << result;

	return 0;
}