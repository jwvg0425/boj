#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	a--;
	b--;
	printf("%d", abs(a % 4 - b % 4) + abs(a / 4 - b / 4));
	return 0;
}