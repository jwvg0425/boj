#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

bool isNotPrime[1000001];

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	isNotPrime[1] = true;

	for (int i = 2; i <= n; i++)
	{
		if (!isNotPrime[i])
		{
			if (i >= m)
				printf("%d\n", i);

			for (int j = i * 2; j <= n; j += i)
				isNotPrime[j] = true;
		}
	}
}