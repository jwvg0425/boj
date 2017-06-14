#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>

int main()
{
	std::set<char> mo = { 'a','e','i','o','u' };

	std::string str;

	std::cin >> str;

	int count = 0;
	for (auto& c : str)
	{
		if (mo.find(c) != mo.end())
			count++;
	}

	printf("%d", count);

	return 0;
}