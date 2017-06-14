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


int fac(int k)
{
	int res = 1;
	for (int i = 2; i <= k; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d", fac(n) / fac(k) / fac(n - k));

	return 0;
}