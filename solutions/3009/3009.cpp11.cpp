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

int main()
{
	std::set<int> xs;
	std::set<int> ys;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		if (xs.find(x) == xs.end())
			xs.insert(x);
		else
			xs.erase(x);

		if (ys.find(y) == ys.end())
			ys.insert(y);
		else
			ys.erase(y);
	}

	int x = *xs.begin();
	int y = *ys.begin();

	printf("%d %d",x,y);
}