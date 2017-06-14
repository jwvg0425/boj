#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int main()
{
	int index = 0;
	int max = 0;

	for (int i = 1; i <= 5; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if (a + b + c + d > max)
		{
			max = a + b + c + d;
			index = i;
		}
	}

	printf("%d %d", index, max);
}