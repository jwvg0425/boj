#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int hp, mp, atk, def;
		int dhp, dmp, datk, ddef;

		scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &atk, &def, &dhp, &dmp, &datk, &ddef);

		hp = std::max(hp + dhp, 1);
		mp = std::max(mp + dmp, 1);
		atk = std::max(atk + datk, 0);
		def += ddef;

		printf("%d\n", hp + 5 * mp + 2 * atk + 2 * def);
	}

	return 0;
}