#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	bool flag = false;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			flag = true;
		}
		else if (str[i] == '+')
		{
			if (flag == true)
				str[i] = '-';
		}
	}

	string inner;
	bool plus = true;
	int total = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (plus == true)
			{
				total += stoi(inner);
				inner.clear();
			}
			else
			{
				total -= stoi(inner);
				inner.clear();
			}

			if (str[i] == '+')
				plus = true;
			else
				plus = false;
		}
		else
		{
			inner += str[i];
		}
	}

	if (plus == true)
	{
		total += stoi(inner);
	}
	else
	{
		total -= stoi(inner);
	}
	cout << total;


	return 0;
}