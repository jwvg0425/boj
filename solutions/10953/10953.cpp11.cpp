#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
}