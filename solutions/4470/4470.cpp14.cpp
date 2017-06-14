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


int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 1; i <= n; i++)
	{
		std::string str;
		std::getline(std::cin, str);

		std::cout << i << ". " << str << std::endl;
	}

	return 0;
}