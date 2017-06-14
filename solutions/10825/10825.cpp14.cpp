#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

struct Student
{
	static Student input()
	{
		Student s;

		std::cin >> s.name >> s.kor >> s.eng >> s.math;

		return s;
	}
	
	bool operator<(const Student& r) const
	{
		if (kor > r.kor)
			return true;

		if (kor < r.kor)
			return false;

		if (eng < r.eng)
			return true;

		if (eng > r.eng)
			return false;

		if (math > r.math)
			return true;

		if (math < r.math)
			return false;

		return name < r.name;
	}


	std::string name;
	int kor;
	int eng;
	int math;
};

int main()
{
	std::ios::sync_with_stdio(false);

	std::vector<Student> students;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		students.push_back(Student::input());

	std::sort(students.begin(), students.end());

	for (auto& s : students)
		std::cout << s.name << "\n";

	return 0;
}