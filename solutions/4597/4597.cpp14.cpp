#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	while (true)
	{
		std::string str;

		std::cin >> str;

		if (str == "#")
			break;

		int count = 0;

		for (auto& c : str)
		{
			if (c == '1')
				count++;
		}

		if (str.back() == 'e')
		{
			if (count % 2 == 0)
				str.back() = '0';
			else
				str.back() = '1';
		}
		else
		{
			if (count % 2 == 0)
				str.back() = '1';
			else
				str.back() = '0';
		}

		std::cout << str << std::endl;
	}
	return 0;
}