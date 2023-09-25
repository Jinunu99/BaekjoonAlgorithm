#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	int count = 0;
	
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		char alpha[26] = { 0 };
		string str;
		cin >> str;
		char pre = str[0]; // 이전 단어를 처음엔 첫단어로

		for (int j = 0; j < str.length(); j++)
		{
			if (alpha[str[j] - 'a'] == 0 || pre == str[j])
			{
				alpha[str[j] - 'a'] += 1;
				pre = str[j];
				
				if (j == str.length() - 1)
					count++;
				continue;
			}
			break;
		}
	}

	cout << count;

	return 0;
}