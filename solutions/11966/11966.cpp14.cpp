#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory.h>
#include <queue>
#include <set>



int main()
{
	int n;

	scanf("%d", &n);

	while (n > 1)
	{
		if (n % 2 == 1)
		{
			printf("0");
			return 0;
		}

		n /= 2;
	}

	printf("1");

	return 0;
}