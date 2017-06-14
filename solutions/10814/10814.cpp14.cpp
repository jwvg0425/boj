#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<std::pair<int, std::string>> arr;

	for (int i = 0; i < n; i++)
	{
		int age;
		std::string name;

		std::cin >> age >> name;

		arr.emplace_back(age, name);
	}

	std::stable_sort(arr.begin(), arr.end(), [](auto& l, auto& r)
	{
		return l.first < r.first;
	});

	for (auto& p : arr)
	{
		std::cout << p.first << ' ' << p.second << std::endl;
	}
	return 0;
}