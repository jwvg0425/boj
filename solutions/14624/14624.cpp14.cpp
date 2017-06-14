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
	int n;
	scanf("%d", &n);

	if (n % 2 == 0)
	{
		printf("I LOVE CBNU");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		printf("*");
	}
	printf("\n");

	for (int y = 0; y < (n + 1) / 2; y++)
	{
		for (int i = 0; i < (n + 1) / 2 + y; i++)
		{
			if (i == (n + 1) / 2 - 1 - y ||
				i == (n + 1) / 2 - 1 + y)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}

	return 0;
}