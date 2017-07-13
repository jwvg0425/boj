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

int scores[2][7] =
{
	{1,2,3,3,4,10},
	{1,2,2,2,3,5,10}
};

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int sum[2] = { 0, };

		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 6 + j; k++)
			{
				int n;
				scanf("%d", &n);

				sum[j] += scores[j][k] * n;
			}
		}

		printf("Battle %d: ", i + 1);

		if (sum[0] > sum[1])
		{
			printf("Good triumphs over Evil\n");
		}
		else if (sum[0] == sum[1])
		{
			printf("No victor on this battle field\n");
		}
		else
		{
			printf("Evil eradicates all trace of Good\n");
		}
	}

	return 0;
}