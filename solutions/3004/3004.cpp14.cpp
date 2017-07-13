#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	int w = 1, h = 1;

	for (int i = 0; i < n; i++)
	{
		if (w == h)
			w++;
		else
			h++;
	}

	printf("%d", w*h);

	return 0;
}