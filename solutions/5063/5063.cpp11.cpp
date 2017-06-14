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
#include <functional>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int r, e, c;

		scanf("%d %d %d", &r, &e, &c);

		if (e - c > r)
			printf("advertise\n");
		else if (e - c == r)
			printf("does not matter\n");
		else
			printf("do not advertise\n");
	}

	return 0;
}