#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%d\n", n * (n + 1) * (2 * n + 1) / 6);
	}

	return 0;
}