#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	while (true)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		if (b - a == c - b)
		{
			printf("AP %d\n", 2 * c - b);
		}
		else
		{
			printf("GP %d\n", c * c / b);
		}
	}

	return 0;
}