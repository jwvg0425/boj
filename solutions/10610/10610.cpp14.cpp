#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>
#include <functional>

int main()
{
	std::string str;

	std::cin >> str;

	int sum = 0;
	int zero = 0;

	for (auto& c : str)
	{
		sum += c - '0';

		if (c == '0')
			zero++;
	}

	if (zero == 0 || sum % 3 != 0)
	{
		printf("-1");
		return 0;
	}

	std::sort(str.begin(), str.end());
	std::reverse(str.begin(), str.end());

	std::cout << str;

	return 0;
}