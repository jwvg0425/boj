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
	int basket[101] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);

	for (int x = 0; x < m; x++)
	{
		int i, j, k;

		scanf("%d %d %d", &i, &j, &k);

		for (int y = i - 1; y <= j - 1; y++)
		{
			basket[y] = k;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", basket[i]);

	return 0;
}