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
	int x[4];
	int y[2];

	for (int i = 0; i < 4; i++)
		scanf("%d", &x[i]);

	for(int  i =0 ; i < 2; i++)
		scanf("%d", &y[i]);

	std::sort(x, x + 4);

	printf("%d", std::max(y[0], y[1]) + x[1] + x[2] + x[3]);

	return 0;
}