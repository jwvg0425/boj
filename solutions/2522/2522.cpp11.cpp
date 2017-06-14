#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n * 2 - 1; i++)
	{
		int k = n - abs(n - i - 1);

		for (int j = 0; j < n - k; j++)
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