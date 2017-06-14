#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int primeArr[100001];

int main()
{
	int t;
	scanf("%d", &t);

	std::vector<int> primes;

	for (int i = 2; i <= 100000; i++)
	{
		if (primeArr[i] != 0)
		{
			continue;
		}

		primes.push_back(i);

		for (int j = i * 2; j <= 100000; j += i)
		{
			primeArr[j] = 1;
		}
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		for (auto& p : primes)
		{
			if (n <= 1 || p > n)
				break;

			if (n%p != 0)
				continue;

			int count = 0;

			while (n % p == 0)
			{
				n /= p;
				count++;
			}

			printf("%d %d\n", p, count);
		}
	}

	return 0;
}