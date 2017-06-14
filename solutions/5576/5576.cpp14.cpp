#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int main()
{
	int w[10];
	int k[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &w[i]);

	for (int i = 0; i < 10; i++)
		scanf("%d", &k[i]);

	std::sort(w, w + 10);
	std::sort(k, k + 10);

	printf("%d %d", w[7] + w[8] + w[9], k[7] + k[8] + k[9]);

	return 0;
}