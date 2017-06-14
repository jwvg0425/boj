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

int seq[1000001];

int main()
{
	int n;
	scanf("%d", &n);

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		seq[k] = seq[k - 1] + 1;

		max = std::max(max, seq[k]);
	}

	printf("%d", n - max);


	return 0;
}