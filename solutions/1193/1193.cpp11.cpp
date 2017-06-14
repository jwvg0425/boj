#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int x;
	scanf("%d", &x);

	int c = 1;
	int s = 0;

	while (s + c < x)
	{
		s += c;
		c++;
	}

	int p = x - s;
	int a = c - p + 1;
	int b = p;

	if (c % 2 == 0)
		std::swap(a, b);

	printf("%d/%d", a, b);
}