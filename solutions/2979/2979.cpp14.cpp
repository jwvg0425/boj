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
	int costs[4] = { 0, };
	scanf("%d %d %d", &costs[1], &costs[2], &costs[3]);

	int start[3];
	int end[3];

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &start[i], &end[i]);

	int total = 0;

	for (int t = 1; t <= 100; t++)
	{
		int c = 0;
		for (int i = 0; i < 3; i++)
		{
			if (start[i] <= t && end[i] > t)
				c++;
		}

		total += c * costs[c];
	}

	printf("%d", total);

	return 0;
}