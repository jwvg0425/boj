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
	int n, m;

	scanf("%d %d", &n, &m);


	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		std::reverse(str.begin(), str.end());

		std::cout << str << std::endl;
	}

	return 0;
}