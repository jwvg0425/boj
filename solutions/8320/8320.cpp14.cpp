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
	int n;

	scanf("%d", &n);

	int count = 0;

	for (int width = 1; width <= n; width++)
	{
		for (int height = width; height <= n / width; height++)
		{
			count++;
		}
	}

	printf("%d", count);

	return 0;
}