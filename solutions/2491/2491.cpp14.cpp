#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int main()
{
	int upcount = 0;
	int downcount = 0;
	int upnum = 0;
	int downnum = 100001;
	int count = 0;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if (a <= downnum)
		{
			downcount++;
		}
		else
		{
			downcount = 1;
		}

		downnum = a;

		if (a >= upnum)
		{
			upcount++;
		}
		else
		{
			upcount = 1;
		}

		upnum = a;

		count = std::max({ count , upcount, downcount });
	}

	printf("%d", count);

	return 0;
}