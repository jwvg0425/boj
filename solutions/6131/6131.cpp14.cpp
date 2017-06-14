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

	for (int b = 1; b <= 500; b++)
	{
		for (int a = b; a <= 500; a++)
		{
			if (b*b + n == a*a)
			{
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}