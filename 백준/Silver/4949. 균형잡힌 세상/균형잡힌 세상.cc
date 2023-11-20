#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// 4949번

int main(void)
{
	while (1)
	{
		string str;
		getline(cin, str);

		stack<char> stk;
		for (int i = 0; i < str.length(); i++)
		{
			if (stk.empty() && (str[i] == ')' || str[i] == ']'))
			{
				stk.push(str[i]);
				break;
			}

			if (str[i] == '(' || str[i] == '[')
			{
				stk.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
					break;
			}
			else if (str[i] == ']')
			{
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
					break;
			}
		}

		if (stk.empty() && str != ".")
			cout << "yes" << '\n';
		else if (!stk.empty() && str != ".")
			cout << "no" << '\n';

		if (str == ".")
			break;
	}

	return 0;
}