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

int main()
{
	std::string checker = "CAMBRIDGE";
	std::string str;

	std::cin >> str;

	for (int i = 0; i < str.size();)
	{
		if (checker.find(str[i]) != -1)
		{
			str.erase(str.begin() + i);
		}
		else
		{
			i++;
		}
	}

	std::cout << str;

	return 0;
}