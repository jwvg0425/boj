#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}

	return 0;
}