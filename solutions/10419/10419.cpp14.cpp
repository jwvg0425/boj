#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int d;
		scanf("%d", &d);

		int k = 0;
		while ((k + 1)*(k + 1) + k + 1 <= d)
		{
			k++;
		}

		printf("%d\n", k);
	}

	return 0;
}