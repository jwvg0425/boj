#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	int sm = sqrt(m);
	int sn = sqrt(n);

	int sum = 0;
	int min = n;

	for (int i = sm; i <= sn; i++)
	{
		int sqr = i*i;

		if (sqr >= m && sqr <= n)
		{
			sum += sqr;
			min = std::min(min, sqr);
		}
	}

	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);

	return 0;
}