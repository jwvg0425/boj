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
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int s = i;
		int k = i;

		while (s > 0)
		{
			k += s % 10;
			s /= 10;
		}

		if (k == n)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("0");

	return 0;
}