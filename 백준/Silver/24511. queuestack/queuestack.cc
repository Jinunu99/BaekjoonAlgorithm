#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	vector<int> decide; // 스택인지 큐인지 저장하는 벡터
	deque<int> inside; // 관리될 상태

	cin >> n;
	for (int i = 0; i < n; i++) {
		int queuestack;
		cin >> queuestack;

		decide.push_back(queuestack);
	}

	for (int i = 0; i < n; i++) {
		int first;
		cin >> first;
		if(decide[i]==0)
			inside.push_back(first);
	}

	int m; // 삽입할 수열의 수
	cin >> m;
	for (int i = 0; i < m; i++) {
		int plus;
		cin >> plus;
		inside.push_front(plus);
	}

	for (int i = 0; i < m; i++) {
		cout << inside.back() << " ";
		inside.pop_back();
	}

	return 0;
}