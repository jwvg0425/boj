#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	std::string str;

	std::cin >> str;

	str.push_back('*');

	bool minus = false;

	int num = 0;
	int res = 0;

	for (auto& c : str)
	{
		if (c >= '0' && c <= '9')
		{
			num = num * 10 + c - '0';
		}
		else
		{
			if (minus)
				res -= num;
			else
				res += num;

			if (c == '-')
				minus = true;
			num = 0;
		}
	}

	printf("%d", res);

	return 0;
}