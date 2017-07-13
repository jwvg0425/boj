#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d", &n);

	std::string pattern;

	std::cin >> pattern;

	int star = 0;

	for (int i = 0; i < pattern.size(); i++)
	{
		if (pattern[i] == '*')
		{
			star = i;
			break;
		}
	}

	std::string front = pattern.substr(0, star);
	std::string back = pattern.substr(star + 1);

	for (int i = 0; i < n; i++)
	{
		std::string folder;
		std::cin >> folder;

		if (folder.size() < pattern.size() - 1)
		{
			printf("NE\n");
			continue;
		}

		if (folder.substr(0, front.size()) == front &&
			folder.substr(folder.size() - back.size()) == back)
		{
			printf("DA\n");
		}
		else
		{
			printf("NE\n");
		}
	}

	return 0;
}