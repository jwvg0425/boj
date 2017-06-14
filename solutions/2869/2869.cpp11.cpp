#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);

	int day = (v - b - 1) / (a - b);

	printf("%d", day + 1);

	return 0;
}