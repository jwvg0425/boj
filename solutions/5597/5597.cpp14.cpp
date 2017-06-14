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

int main()
{
	bool visit[31] = { false, };

	for (int i = 0; i < 28; i++)
	{
		int k;
		scanf("%d", &k);

		visit[k] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!visit[i])
			printf("%d\n", i);
	}

	return 0;
}