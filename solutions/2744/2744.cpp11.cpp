#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	std::string str;

	std::cin >> str;

	for (auto& c : str)
	{
		if (c >= 'a' && c <= 'z')
			c = c - 'a' + 'A';
		else
			c = c - 'A' + 'a';
	}

	std::cout << str;

	return 0;
}