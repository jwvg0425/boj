#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int n;
	scanf("%d", &n);

	std::string str;

	std::cin >> str;

	int sum = 0;

	for (auto& c : str)
	{
		sum += c - '0';
	}

	printf("%d", sum);
}