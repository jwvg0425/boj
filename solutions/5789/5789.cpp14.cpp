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


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		int mid = str.size() / 2 - 1;

		printf("Do-it%s\n", str[mid] == str[mid + 1] ? "" : "-Not");
	}

	return 0;
}