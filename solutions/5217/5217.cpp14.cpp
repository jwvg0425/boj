#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#define MAX 987654321

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;

		scanf("%d", &n);

		printf("Pairs for %d: ", n);

		for (int i = 1; i <= n / 2; i++)
		{
			int j = n - i;
			if (i == j)
				break;

			printf("%s%d %d", (i == 1) ? "" : ", ", i, j);
		}

		printf("\n");
	}

	return 0;
}