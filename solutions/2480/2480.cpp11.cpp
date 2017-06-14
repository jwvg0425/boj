#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c)
		printf("%d", 10000 + a * 1000);
	else if (a == b)
		printf("%d", 1000 + 100 * a);
	else if (b == c)
		printf("%d", 1000 + 100 * b);
	else if (c == a)
		printf("%d", 1000 + 100 * c);
	else
		printf("%d", std::max({ a,b,c }) * 100);
}