#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	long long int s;

	scanf("%lld", &s);

	long long int n = sqrt(2 * s);

	if (n*(n + 1) / 2 > s)
		n--;

	printf("%d", n);

	return 0;
}