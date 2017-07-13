#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	if (a > b)
		std::swap(a, b);

	if (a == b)
	{
		printf("0");
		return 0;
	}

	printf("%lld\n", b - a - 1);

	for (long long int i = a + 1; i < b; i++)
	{
		printf("%lld ", i);
	}

	return 0;
}