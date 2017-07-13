#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	std::string password;

	std::cin >> password;

	int n;
	scanf("%d", &n);

	std::vector<std::string> dict;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		dict.push_back(str);
	}

	for (int i = 0; i < 26; i++)
	{
		std::string changed;

		for (auto& c : password)
		{
			changed.push_back('a' + (c - 'a' + i) % 26);
		}

		for (auto& d : dict)
		{
			if (changed.find(d) != std::string::npos)
			{
				std::cout << changed;
				return 0;
			}
		}
	}

	return 0;
}