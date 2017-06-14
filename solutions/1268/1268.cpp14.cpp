#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int main()
{
	int in[1001][5];
	int n;
	int count[1001] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &in[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (in[i][k] == in[j][k])
				{
					count[i]++;
					break;
				}
			}
		}
	}

	int max = 0;

	for (int i = 1; i < n; i++)
	{
		if (count[max] < count[i])
			max = i;
	}

	printf("%d", max + 1);


	return 0;
}