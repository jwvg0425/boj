#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

bool isNotPrime[1000000];

int main()
{
	//prime 찾기
	isNotPrime[2] = false;

	for (int i = 2; i <= 1000000; i++)
	{
		if (isNotPrime[i])
			continue;

		for (int j = i * 2; j <= 1000000; j+= i)
		{
			isNotPrime[j] = true;
		}
	}

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		for (int j = 3; j <= n; j++)
		{
			if (!isNotPrime[j] && !isNotPrime[n - j])
			{
				printf("%d = %d + %d\n", n, j, n - j);
				break;
			}
		}
	}

	return 0;
}