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
	int c = 0;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		c += a;
	}

	if (c >= (n+1) / 2)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");

	return 0;
}