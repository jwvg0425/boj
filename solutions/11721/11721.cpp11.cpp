#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	std::string str;

	std::cin >> str;

	for (int i = 0; i < str.size(); i+= 10)
	{
		for (int j = i; j < std::min(i + 10, (int)str.size()); j++)
		{
			printf("%c", str[j]);
		}
		printf("\n");
	}
}