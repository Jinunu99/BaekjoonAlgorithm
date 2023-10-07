#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> input1;
	vector<string> input2;

	vector<string> output;

	for (int i = 0; i < n; i++)
	{
		string name1;
		cin >> name1;
		input1.push_back(name1);
	}

	for (int j = 0; j < m; j++)
	{
		string name2;
		cin >> name2;

		input2.push_back(name2);
	}

	sort(input1.begin(), input1.end());
	sort(input2.begin(), input2.end());
	set_intersection(input1.begin(), input1.end(), input2.begin(), input2.end(), inserter(output, output.begin()));


	//sort(output.begin(), output.end());

	cout << output.size() << "\n";
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "\n";
	}
	return 0;
}