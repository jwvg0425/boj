#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

struct Person
{
	std::string name;
	int year;
	int month;
	int day;

	bool operator<(const Person& r)
	{
		if (year < r.year)
			return true;

		if (year > r.year)
			return false;

		if (month < r.month)
			return true;

		if (month > r.month)
			return false;

		return day < r.day;
	}

	bool operator==(const Person& r)
	{
		return year == r.year && month == r.month && day == r.day;
	}

	bool operator>(const Person& r)
	{
		return !((*this) < r) && !((*this) == r);
	}
};

int main()
{
	int n;

	scanf("%d", &n);

	Person min;
	Person max;

	for (int i = 0; i < n; i++)
	{
		Person p;

		std::cin >> p.name >> p.day >> p.month >> p.year;

		if (i == 0)
			min = p;
		else if (p < min)
			min = p;

		if (i == 0)
			max = p;
		else if (p > max)
			max = p;
	}

	std::cout << max.name << std::endl << min.name;

	return 0;
}