#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n;

	scanf("%d", &n);

	int circle = (n + 4) / 6;

	int i = 1;
	int sum = 0;

	while (sum < circle)
	{
		sum += i;
		i++;
	}

	printf("%d", i);
}