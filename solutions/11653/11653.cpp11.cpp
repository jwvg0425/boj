#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int n;
	scanf("%d", &n);

	int i = 2;

	while (n > 1)
	{
		if (n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
		}
		else
		{
			i++;
		}
	}
}