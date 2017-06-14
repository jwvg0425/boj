#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < 2 * n - 1; i++)
	{
		int k = n - abs(n - i - 1);

		for (int j = 0; j < k; j++)
			printf("*");

		puts("");
	}
}