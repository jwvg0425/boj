#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("%d", std::min(a + d, b + c));
	return 0;
}