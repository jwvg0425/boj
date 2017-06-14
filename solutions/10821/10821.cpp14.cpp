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
	std::string str;

	std::cin >> str;

	int count = 1;

	for (auto& c : str)
		if (c == ',')
			count++;

	printf("%d", count);

	return 0;
}