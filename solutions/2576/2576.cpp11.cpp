#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int min = 101;
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		int k;
		scanf("%d", &k);

		if (k % 2 == 0)
			continue;

		sum += k;
		min = std::min(k, min);
	}

	if (min == 101)
	{
		printf("-1");
		return 0;
	}

	printf("%d\n%d", sum, min);

	return 0;
}