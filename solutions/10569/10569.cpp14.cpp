#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int v, e;
		scanf("%d %d", &v, &e);

		printf("%d\n", 2 + e - v);
	}

	return 0;
}