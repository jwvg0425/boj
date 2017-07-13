#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int j = 0; j < 6; j++)
		{
			int k;
			scanf("%d", &k);
			sum += k;
		}
		int day = 1;

		while (n >= sum)
		{
			day++;
			sum *= 4;
		}

		printf("%d\n", day);
	}
	return 0;
}