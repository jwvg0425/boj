#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		std::string str;

		std::cin >> str;

		std::set<char> s;

		for (auto& c : str)
			s.insert(c);

		printf("%d\n", s.size());
	}

	return 0;
}