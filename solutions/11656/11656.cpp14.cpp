#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

int main()
{
	std::string str;

	std::cin >> str;

	std::vector<std::string> suffix;

	for (int i = 0; i < str.size(); i++)
	{
		suffix.push_back(str.substr(i));
	}

	std::sort(suffix.begin(), suffix.end());

	for (auto& s : suffix)
	{
		std::cout << s << std::endl;
	}

	return 0;
}