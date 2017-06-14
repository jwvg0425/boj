#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>

bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;

	scanf("%d", &n);

	int min = -1;
	int max = -1;
	int ori = 0;

	for (int i = 0; i < n; i++)
	{
		int h;
		scanf("%d", &h);

		if (min == -1)
		{
			min = h;
			max = h;
		}
		else
		{
			if (h <= max)
			{
				ori = std::max(ori, max - min);
				min = h;
				max = h;
			}
			else
			{
				max = h;
			}
		}
	}

	ori = std::max(ori, max - min);

	printf("%d", ori);

	return 0;
}