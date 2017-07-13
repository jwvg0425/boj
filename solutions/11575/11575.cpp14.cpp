#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		std::string str;

		std::cin >> str;

		for (auto &c : str)
			printf("%c", 'A' + (a * (c - 'A') + b) % 26);

		printf("\n");
	}

	return 0;
}