#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}

		for (int j = 0; j < i * 2 + 1; j++)
		{
			if (j == 0 || j == i * 2)
				printf("*");
			else
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}