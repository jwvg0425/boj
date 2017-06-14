#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int words = 0;
	std::string str;
	while (std::cin >> str) words++;

	printf("%d", words);
}