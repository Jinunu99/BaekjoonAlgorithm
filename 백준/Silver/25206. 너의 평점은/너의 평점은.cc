#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string name;
	float point;
	string grade;
	vector<string> gradeEng = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F" };
	vector<float> gradePoint = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0 };
	float sum = 0;
	int gradeSum = 0;

	for (int i = 0; i < 20; i++)
	{
		cin >> name >> point >> grade;
		if (grade != "P")
		{
			sum += point * gradePoint[find(gradeEng.begin(), gradeEng.end(), grade) - gradeEng.begin()];
			gradeSum += point;
		}
	}

	cout << sum / gradeSum;

	return 0;
}