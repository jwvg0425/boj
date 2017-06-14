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
	int n;
	scanf("%d", &n);

	int sec = 0;

	while (n > 0)
	{
		int k = 0;

		for (int i = 1; k + i <= n; i++)
		{
			k += i;
			sec++;
		}

		n -= k;
	}

	printf("%d",sec);

	return 0;
}