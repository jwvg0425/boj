#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>

int count(int n, int k)
{
	int c = 0;

	while (n > 0)
	{
		c += n / k;
		n /= k;
	}

	return c;
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	int five = count(n, 5) - count(m, 5) - count(n - m, 5);
	int two = count(n, 2) - count(m, 2) - count(n - m, 2);

	printf("%d", std::min(two, five));

	return 0;
}