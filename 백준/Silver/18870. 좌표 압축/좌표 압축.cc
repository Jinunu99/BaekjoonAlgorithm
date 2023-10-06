#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> input;
	vector<int> output(n);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		
		input.push_back(x); // 입력받은 원소 넣고
	}

	vector<int> r(input); // 원본 복사
	sort(r.begin(), r.end()); // 복사한거 정렬
	r.erase(unique(r.begin(), r.end()), r.end()); // 중복제거

	for (int i = 0; i < n; i++) // 입력받은 원소가 정렬된 인덱스의 몇번째 인지 출력
	{
		cout<< lower_bound(r.begin(), r.end(), input[i]) - r.begin() <<" ";
	}


	return 0;
}