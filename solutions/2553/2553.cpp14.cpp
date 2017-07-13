#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	long long int fac = 1;

	for (int i = 2; i <= n; i++)
	{
		fac *= i;

		while (fac % 10 == 0)
			fac /= 10;

		fac %= 1000000;
	}

	printf("%lld", fac % 10);

	return 0;
}