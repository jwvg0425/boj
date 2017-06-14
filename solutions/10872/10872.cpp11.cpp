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

	long long int mult = 1;

	for (long long int i = 1; i <= n; i++)
	{
		mult *= i;
	}

	printf("%lld", mult);
}