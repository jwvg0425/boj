#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int order(int n, int r, int c)
{
	if (n == 1)
	{
		return 0;
	}

	int half = n / 2;

	int k = r / half * 2 + c / half;

	r %= half;
	c %= half;

	return half * half * k + order(half, r, c);
}

int main()
{
	int n, r, c;

	scanf("%d %d %d", &n, &r, &c);

	int pow = (1 << n);

	printf("%d", order(pow, r, c));

	return 0;
}