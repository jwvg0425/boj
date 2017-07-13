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
	int x[3], y[3];

	int p12x, p12y;
	int p23x, p23y;

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);

	p12x = x[1] - x[0];
	p12y = y[1] - y[0];
	p23x = x[2] - x[1];
	p23y = y[2] - y[1];

	int z = p12x * p23y - p12y * p23x;

	if (z > 0)
		printf("1");
	else if (z == 0)
		printf("0");
	else
		printf("-1");

	return 0;
}