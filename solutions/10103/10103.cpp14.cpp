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
	int a = 100, b = 100;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		if (x > y)
			b -= x;
		else if (x < y)
			a -= y;
	}

	printf("%d\n%d", a, b);
	
	return 0;
}