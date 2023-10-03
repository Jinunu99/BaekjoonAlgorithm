#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 10814번

struct Person {
	int age;
	string name;
};

bool compare(const Person& a, const Person& b)
{
	return a.age < b.age;
}

int main(void)
{
	int n;
	cin >> n;

	vector<Person> per;
	Person ex;
	int input_age;
	string input_name;

	for (int i = 0; i < n; i++)
	{
		cin >> input_age >> input_name;
		ex.age = input_age;
		ex.name = input_name;

		per.push_back(ex);
	}
	
	stable_sort(per.begin(), per.end(), compare);

	for (int i = 0; i < per.size(); i++)
	{
		cout << per[i].age << " " << per[i].name << "\n";
	}

	return 0;
}