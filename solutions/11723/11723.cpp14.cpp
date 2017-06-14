#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int s = 0;

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		char command[20];

		scanf("%s", command);

		if (!strcmp(command,"add"))
		{
			int x;
			scanf("%d", &x);

			s |= (1 << x);
		}
		else if (!strcmp(command,"remove"))
		{
			int x;
			scanf("%d", &x);

			s &= ~(1 << x);
		}
		else if (!strcmp(command, "check"))
		{
			int x;
			scanf("%d", &x);

			printf("%d\n", (s & (1 << x)) != 0 ? 1 : 0);
		}
		else if (!strcmp(command, "toggle"))
		{
			int x;
			scanf("%d", &x);

			s ^= (1 << x);

		}
		else if (!strcmp(command, "all"))
		{
			s = (1 << 21) - 1;
		}
		else if (!strcmp(command, "empty"))
		{
			s = 0;
		}
	}

	return 0;
}