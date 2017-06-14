#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	long long int sum = 0;

	for (auto& c : a)
		for (auto& c2 : b)
			sum += (c - '0') * (c2 - '0');

	printf("%lld", sum);
	return 0;
}