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

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;

	for (int low = 0; low <= n; low++)
	{
		for (int high = 0; high <= low; high++)
		{
			count += low + high;
		}
	}

	printf("%d", count);

	return 0;
}