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
	int n;
	scanf("%d", &n);

	int digit = 10;

	while (n > digit)
	{
		int r = n % digit;
		n -= r;

		if (r >= digit / 2)
		{
			n += digit;
		}

		digit *= 10;
	}

	printf("%d", n);

	return 0;
}