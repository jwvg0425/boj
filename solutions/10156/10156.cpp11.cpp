#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int k, n, m;

	scanf("%d %d %d", &k, &n, &m);

	printf("%d", std::max(0, k*n - m));

	return 0;
}