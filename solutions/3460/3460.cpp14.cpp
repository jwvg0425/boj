#include<stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int pos = 0;

		while (n > 0)
		{
			if (n % 2 == 1)
				printf("%d ", pos);

			n /= 2;
			pos++;
		}

		printf("\n");
	}

	return 0;
}