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

	long long int counts[32] = { 0, };

	for (int i = 0; i < n; i++)
	{
		int name;
		scanf("%d", &name);

		int idx = 0;

		while (name > 0)
		{
			if (name % 2 == 1)
				counts[idx]++;

			name /= 2;
			idx++;
		}
	}

	long long int total = 0;

	for (int i = 0; i < 32; i++)
	{
		total += (1LL << i) * counts[i] * (n - counts[i]);
	}

	printf("%lld", total);

	return 0;
}