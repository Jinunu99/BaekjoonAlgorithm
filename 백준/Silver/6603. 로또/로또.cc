// 6603

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[13] = { 0 };
int result[6] = { 0 };
int input;

void dfs(int start, int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << result[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = start; i < input; i++)
	{
		result[depth] = arr[i];
		dfs(i + 1, depth + 1);
	}
}

int main(void)
{
	while (1)
	{
		cin >> input;
		if (input == 0)
			break;

		for (int i = 0; i < input; i++)
		{
			cin >> arr[i];
		}

		dfs(0, 0);
		cout << "\n";
	}


	return 0;
}