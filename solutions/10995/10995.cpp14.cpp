#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int c = n * 2;
		if (i % 2 == 0)
			c--;

		for (int j = 0; j < c; j++)
		{
			printf("%c", (i + j) % 2 == 0 ? '*' : ' ');
		}
		printf("\n");
	}

	return 0;
}