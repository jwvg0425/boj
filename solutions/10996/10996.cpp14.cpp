#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	if (n == 1)
	{
		printf("*");
		return 0;
	}

	for (int y = 0; y < n * 2; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if ((x + y) % 2 == 0)
				printf("*");
			else
				printf(" ");
		}

		printf("\n");
	}


	return 0;
}