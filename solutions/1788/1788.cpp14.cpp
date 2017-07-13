#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	int pprev = 0;
	int prev = 0;
	int now = 1;

	if (n == 0)
		now = 0;

	for (int i = 1; i < abs(n); i++)
	{
		pprev = prev;
		prev = now;

		now = (prev + pprev) % 1000000000;
	}

	if (n > 0)
		printf("1\n");
	else if (n == 0)
		printf("0\n");
	else if (abs(n) % 2 == 0)
		printf("-1\n");
	else
		printf("1\n");

	printf("%d", now);
	
	return 0;
}