#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int main()
{
	bool visit[42] = { false, };
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		int a;

		scanf("%d", &a);

		if (!visit[a % 42])
		{
			visit[a % 42] = true;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}