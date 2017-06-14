#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>
#include <map>

int main()
{
	std::map<int, int> cards;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int card;

		scanf("%d", &card);

		cards[card]++;
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);

		printf("%d ", cards[a]);
	}

	return 0;
}