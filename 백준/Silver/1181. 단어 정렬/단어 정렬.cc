#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;

	else // 길이가 다르면
		return a.size() < b.size();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}