#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string alpha;
	cin >> alpha;

	vector<string> exam = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

	for (int i = 0; i < exam.size(); i++)
	{
		while (alpha.find(exam[i]) != string::npos)
		{
			alpha.replace(alpha.find(exam[i]), exam[i].length(), "?");
		}
	}

	cout << alpha.length();
	return 0;
}