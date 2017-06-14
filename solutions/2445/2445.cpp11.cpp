#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i < 2 * n; i++)
	{
		int k = n - abs(n - i);

		for (int j = 0; j < k; j++)
		{
			printf("*");
		}

		for (int j = 0; j < 2 * n - 2 * k; j++)
		{
			printf(" ");
		}

		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}