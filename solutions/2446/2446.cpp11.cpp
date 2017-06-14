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

	for (int i = 0; i < 2 * n - 1; i++)
	{
		int t = abs(n - i - 1);
		int star = t * 2 + 1;

		for (int j = 0; j < n - t - 1; j++)
		{
			printf(" ");
		}

		for (int j = 0; j < star; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}