#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>

int primeArr[4000001];

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> primes;

	for (int i = 2; i <= n; i++)
	{
		if (primeArr[i] != 0)
			continue;

		primes.push_back(i);

		for (int j = i * 2; j <= n; j += i)
		{
			primeArr[j] = 1;
		}
	}
	int left = 0, right =1;
	int sum = primes.empty() ? 0 : primes[0];
	int count = 0;

	while (!primes.empty())
	{
		if (sum == n)
			count++;

		if (left == primes.size() - 1)
			break;

		if (sum < n)
		{
			sum += primes[right];
			right++;
		}
		else
		{
			sum -= primes[left];
			left++;
		}
	}

	printf("%d", count);

	return 0;
}