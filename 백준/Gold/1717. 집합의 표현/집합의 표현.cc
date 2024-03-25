#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int parent(int x) // 집합에서 대표부모를 찾는 것
{
	if (v[x] == x)
		return x;
	else
		return v[x] = parent(v[x]); // 연결된 노드를 대표부모로 변경
}

void un(int a, int b)
{
	a = parent(a);
	b = parent(b);

	if (a != b) // 대표부모가 다르면 b의 대표부모를 a의 대표부모로 변경
		v[b] = a;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		v[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int f, a, b;
		cin >> f >> a >> b;

		if (f == 0)
		{
			un(a, b);
		}
		else
		{
			if (parent(a) == parent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}


	return 0;
}