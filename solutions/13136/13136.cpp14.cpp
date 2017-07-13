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
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);

	long long int nr = (r + n - 1) / n;
	long long int nc = (c + n - 1) / n;

	printf("%lld", nr*nc);

	return 0;
}