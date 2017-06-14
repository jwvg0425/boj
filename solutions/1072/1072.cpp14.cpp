#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
	long long int x, y;

	while (~scanf("%lld %lld", &x, &y))
	{
		int percent = 100 * y / x;

		//99% 이상이면 불가능함
		if (percent >= 99)
		{
			printf("-1\n");
			continue;
		}

		long long int left = 1;
		long long int div = 99 * x - 100 * y;
		long long int right = (x * x + div - 1) / div;
		long long int k = right;

		while (left <= right)
		{
			long long int mid = (left + right) / 2;

			if (100 * (y + mid) / (x + mid) > percent)
			{
				k = std::min(k, mid);
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		printf("%d\n", k);
	}

	return 0;
}