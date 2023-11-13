#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 1541번 잃어버린 괄호

int main(void)
{
	string str;
	cin >> str;

	bool flag = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
			flag = true;
		else if (str[i] == '+' && flag == true)
			str.replace(i, 1, "-");
	}

	int idx = 0;
	bool plus = true;

	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (str[i] == '-')
				plus = false;

			idx = i;
			break;
		}
	}
	
	int result = stoi(str.substr(0, idx + 1));
	string temp;

	for (int i = idx + 1; i <= str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (plus == true)
			{
				result += stoi(temp);
			}
			else
			{
				result -= stoi(temp);
			}

			if (str[i] == '+')
				plus = true;
			else
				plus = false;

			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}

	cout << result;

	return 0;
}