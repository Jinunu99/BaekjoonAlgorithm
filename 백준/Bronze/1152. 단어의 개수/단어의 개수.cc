#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	
	int count = 0;
	int gap = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
		{
			if (gap == 1)
				count += 1;

			gap = 0;
		}
		else {
			gap = 1;
		}
	}

	cout << count;

	return 0;
}