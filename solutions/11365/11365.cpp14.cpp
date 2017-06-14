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

int main()
{
	while (true)
	{
		std::string str;

		std::getline(std::cin, str);

		if (str == "END")
			break;

		std::reverse(str.begin(), str.end());

		std::cout << str << std::endl;
	}

	return 0;
}