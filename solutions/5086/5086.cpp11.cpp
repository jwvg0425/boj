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
	while (true)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == b)
			break;

		if (a%b == 0)
			printf("multiple\n");
		else if(b%a == 0)
			printf("factor\n");
		else
			printf("neither\n");
	}

	return 0;
}