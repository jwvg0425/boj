#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (c <= b)
	{
		printf("-1");
		return 0;
	}

	int num = 1 + a / (c - b);

	printf("%d", num);

	return 0;
}