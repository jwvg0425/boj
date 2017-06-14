#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
			count++;

		if (count == k)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("0");

	return 0;
}