#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int count[10001] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		count[k] ++;
	}

	for (int i = 0; i <= 10000; i++)
	{
		while (count[i] > 0)
		{
			printf("%d\n", i);
			count[i]--;
		}
	}

	return 0;
}