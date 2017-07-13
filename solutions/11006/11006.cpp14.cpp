#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int chic, leg;

		scanf("%d %d", &leg, &chic);

		printf("%d %d\n", 2 * chic-leg, leg - chic);
	}

	return 0;
}