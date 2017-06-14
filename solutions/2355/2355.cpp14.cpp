#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	long long int start, end;

	if (a * b > 0)
	{
		long long int min = std::min(std::abs(a), std::abs(b)), max = std::max(std::abs(a), std::abs(b));
		long long int s = max * (max + 1) / 2 - min * (min - 1) / 2;

		if (a < 0)
			s = -s;

		printf("%lld", s);
	}
	else
	{
		long long int min = std::abs(std::min(a, b)), max = std::abs(std::max(a, b));
		long long int s = max * (max + 1) / 2 - min * (min + 1) / 2;

		printf("%lld", s);
	}

	return 0;
}