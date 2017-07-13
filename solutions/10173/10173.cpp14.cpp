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

char lower(char c)
{
	if (c <= 'Z' && c >= 'A')
		return c - 'A' + 'a';

	return c;
}

int main()
{
	while (true)
	{
		std::string str;

		std::getline(std::cin, str);

		if (str == "EOI")
			break;

		std::transform(str.begin(), str.end(), str.begin(), lower);

		if (str.find("nemo", 0) == std::string::npos)
		{
			printf("Missing\n");
		}
		else
		{
			printf("Found\n");
		}

	}
	return 0;
}