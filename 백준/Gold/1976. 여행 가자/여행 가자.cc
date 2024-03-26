#include <iostream>

using namespace std;

int arr[201] = { 0 };
int connect[201][201] = { 0 };

int parent(int x) // 해당 집합의 부모 노드를 찾자
{
	if (arr[x] == x) // 자기자신의 번호를 가지고 있으면 해당 집합의 부모이다
		return x;
	else
		return arr[x] = parent(arr[x]); // 재귀를 나오면서 자신이 속한 부모노드를 가리켜줌
}

void un(int a, int b)
{
	// 해당 노드의 부모를 가져오고
	a = parent(a);
	b = parent(b);

	if (a != b) // 부모가 다르면
	{
		arr[b] = a;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> connect[i][j];

			if (i < j && connect[i][j] == 1)
			{
				un(i, j);
			}
		}
	}

	int flag = 1;
	int temp = 0;
	for (int i = 0; i < m; i++)
	{
		int ipt;
		cin >> ipt;
		if (i == 0)
		{
			temp = parent(arr[ipt]);
		}
		else
		{
			if (temp != parent(arr[ipt]))
				flag = 0;
		}

	}
	
	if (flag == 1)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}