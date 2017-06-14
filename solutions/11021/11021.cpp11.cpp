#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		printf("Case #%d: %d\n", i, a + b);
	}
}