#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int k = sqrt(n);

	if (k*k < n)
		k++;

	printf("%lld", k);

	return 0;
}