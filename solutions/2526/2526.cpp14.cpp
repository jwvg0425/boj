#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n, p;

	scanf("%d %d", &n, &p);

	int m = n;

	int visit[100] = { 0, };
	int k = 0;

	while (true)
	{
		if (visit[n] != 0)
		{
			printf("%d", k - visit[n] + 1);
			return 0;
		}
		else
		{
			k++;
			visit[n] = k;
			n = (n*m) % p;
		}
	}

	return 0;
}