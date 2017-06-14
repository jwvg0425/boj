#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>


int main()
{
	int k;

	int a = 1, b = 0;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int na = b, nb = a + b;

		a = na;
		b = nb;
	}

	printf("%d %d", a, b);

	return 0;
}