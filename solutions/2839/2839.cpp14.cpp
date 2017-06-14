#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n;

	scanf("%d", &n);

	int table[5001] = { 0, -1, -1, 1, -1, 1 };

	for (int i = 6; i <= n; i++)
	{
		int k1 = table[i - 5];
		int k2 = table[i - 3];

		if (k1 != -1 && k2 != -1)
			table[i] = std::min(k1, k2) + 1;
		else if (k1 != -1 && k2 == -1)
			table[i] = k1 + 1;
		else if (k1 == -1 && k2 != -1)
			table[i] = k2 + 1;
		else
			table[i] = -1;
	}

	printf("%d", table[n]);
}