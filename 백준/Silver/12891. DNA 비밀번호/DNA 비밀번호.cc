#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, p;
	cin >> s >> p;
	string str;
	cin >> str;

	int min_cnt[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		cin >> min_cnt[i];
	}

	int cnt[4] = { 0 };
	int count = 0;

	for (int j = 0; j < p; j++)
	{
		if (str[j] == 'A')
			cnt[0]++;
		else if (str[j] == 'C')
			cnt[1]++;
		else if (str[j] == 'G')
			cnt[2]++;
		else if (str[j] == 'T')
			cnt[3]++;
	}
	for (int j = 0; j < 4; j++)
	{
		if (min_cnt[j] > cnt[j])
			break;

		if (min_cnt[j] <= cnt[j] && j == 3)
			count++;
	}

	
	for (int i = p; i < s; i++)
	{
		if (str[i] == 'A')
			cnt[0]++;
		else if (str[i] == 'C')
			cnt[1]++;
		else if (str[i] == 'G')
			cnt[2]++;
		else if (str[i] == 'T')
			cnt[3]++;

		if (str[i-p] == 'A')
			cnt[0]--;
		else if (str[i-p] == 'C')
			cnt[1]--;
		else if (str[i-p] == 'G')
			cnt[2]--;
		else if (str[i-p] == 'T')
			cnt[3]--;


		for (int j = 0; j < 4; j++)
		{
			if (min_cnt[j] > cnt[j])
				break;

			if (min_cnt[j] <= cnt[j] && j == 3)
				count++;
		}
	}
	cout << count;


	return 0;
}