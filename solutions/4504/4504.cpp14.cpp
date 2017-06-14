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
	scanf("%d\n", &n);

	while (true)
	{
		int k;

		scanf("%d", &k);
		
		if (k == 0)
			break;

		printf("%d is%sa multiple of %d.\n", k, (k%n == 0) ? " " : " NOT ", n);
	}

	return 0;
}