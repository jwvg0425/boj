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
	bool sit[101] = { false, };
	int count = 0;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		if (sit[k])
			count++;
		sit[k] = true;
	}

	printf("%d", count);

	return 0;
}