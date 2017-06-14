#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

void solve()
{
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);

	int floor = n % h;
	int room = (n-1) / h + 1;

	if (floor == 0)
		floor = h;

	if (h == 1)
	{
		floor = 1;
		room = n;
	}

	printf("%d\n", floor * 100 + room);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
}