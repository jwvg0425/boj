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

	for (auto& c : str)
	{
		c = (c - 'A' + 23) % 26 + 'A';
	}

	std::cout << str;

	return 0;
}