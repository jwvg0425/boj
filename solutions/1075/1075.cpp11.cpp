#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int n, f;

	scanf("%d %d", &n, &f);

	for (int i = 0; i < 100; i++)
	{
		int nn = n / 100 * 100 + i;

		if (nn%f == 0)
		{
			printf("%02d", i);
			return 0;
		}
	}

	return 0;
}