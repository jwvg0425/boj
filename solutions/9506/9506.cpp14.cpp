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
#include <functional>
#include <stack>

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == -1)
			break;

		std::vector<int> primes;
		int s = 0;

		for (int i = 1; i < n; i++)
		{
			if (n %i == 0)
			{
				primes.push_back(i);
				s += i;
			}
		}

		if (n != s)
		{
			printf("%d is NOT perfect.\n", n);
		}
		else
		{
			printf("%d = ", n);

			for (int i = 0; i < primes.size() - 1; i++)
			{
				printf("%d + ", primes[i]);
			}

			printf("%d\n", primes.back());
		}
	}


	return 0;
}