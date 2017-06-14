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
#include <deque>

int main()
{
	int m, d;
	scanf("%d %d", &m, &d);

	if (m < 2)
	{
		printf("Before");
	}
	else if (m > 2)
	{
		printf("After");
	}
	else if (d < 18)
	{
		printf("Before");
	}
	else if (d > 18)
	{
		printf("After");
	}
	else
	{
		printf("Special");
	}

	return 0;
}