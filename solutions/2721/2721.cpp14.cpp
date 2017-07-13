#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		long long int n;
		scanf("%lld", &n);

		long long int sum = 0;

		for (int j = 1; j <= n; j++)
		{
			sum += j * (j + 1) * (j + 2) / 2;
		}

		printf("%lld\n", sum);
	}


	return 0;
}