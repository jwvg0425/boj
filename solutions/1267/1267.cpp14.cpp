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
	int n;
	scanf("%d", &n);

	int y = 0, m = 0;

	for (int i = 0; i < n; i++)
	{
		int call;
		scanf("%d", &call);
		y += ((call + 30) / 30) * 10;
		m += ((call + 60) / 60) * 15;
	}

	if (y == m)
		printf("Y M");
	else if (y > m)
		printf("M");
	else
		printf("Y");

	printf(" %d", std::min(y, m));

	return 0;
}