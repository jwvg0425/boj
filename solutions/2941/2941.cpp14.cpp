#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
	std::vector<std::string> croatia =
	{
		"c=",
		"c-",
		"dz=",
		"d-",
		"lj",
		"nj",
		"s=",
		"z="
	};

	int count = 0;

	std::string word;

	std::cin >> word;

	for (int i = 0; i < word.size();)
	{
		int next = 1;
		for (auto& c : croatia)
		{
			if (word.substr(i, c.size()) == c)
			{
				//크로아티아 알파벳
				next = c.size();
				break;
			}
		}
		count++;
		i += next;
	}

	printf("%d", count);

	return 0;
}